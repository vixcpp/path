/**
 *
 *  @file path_test.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.
 *  All rights reserved.
 *  https://github.com/vixcpp/vix
 *
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <vix/path/Absolute.hpp>
#include <vix/path/Basename.hpp>
#include <vix/path/Dirname.hpp>
#include <vix/path/Extension.hpp>
#include <vix/path/Filename.hpp>
#include <vix/path/HasExtension.hpp>
#include <vix/path/IsAbsolute.hpp>
#include <vix/path/IsRelative.hpp>
#include <vix/path/Join.hpp>
#include <vix/path/LexicallyNormal.hpp>
#include <vix/path/LexicallyProximate.hpp>
#include <vix/path/LexicallyRelative.hpp>
#include <vix/path/Normalize.hpp>
#include <vix/path/Parent.hpp>
#include <vix/path/PathOptions.hpp>
#include <vix/path/ReplaceExtension.hpp>
#include <vix/path/Separator.hpp>
#include <vix/path/Split.hpp>
#include <vix/path/Stem.hpp>
#include <vix/path/Relative.hpp>

namespace
{

  void assert_true(bool condition, const std::string &message)
  {
    if (!condition)
    {
      std::cerr << "[FAIL] " << message << '\n';
      std::exit(EXIT_FAILURE);
    }
  }

  void assert_equal(const std::string &actual,
                    const std::string &expected,
                    const std::string &message)
  {
    if (actual != expected)
    {
      std::cerr << "[FAIL] " << message
                << " | expected='" << expected
                << "' actual='" << actual << "'\n";
      std::exit(EXIT_FAILURE);
    }
  }

  void test_separator_helpers()
  {
    using namespace vix::path;

    assert_true(is_separator('/'), "Slash should be recognized as separator.");
    assert_true(is_separator('\\'), "Backslash should be recognized as separator.");
    assert_true(!is_separator('x'), "Regular character should not be recognized as separator.");

    assert_true(has_leading_separator("/tmp"), "Leading separator should be detected.");
    assert_true(has_trailing_separator("/tmp/"), "Trailing separator should be detected.");
    assert_true(!has_trailing_separator("/tmp/file.txt"), "Trailing separator should not be detected.");
  }

  void test_join_posix()
  {
    using namespace vix::path;

    PathOptions options;
    options.style = PathStyle::Posix;

    auto joined = join("/usr/", "/bin", options);
    assert_true(static_cast<bool>(joined), "join should succeed for POSIX paths.");
    assert_equal(joined.value(), "/usr/bin", "join should normalize repeated separators.");
  }

  void test_join_windows()
  {
    using namespace vix::path;

    PathOptions options;
    options.style = PathStyle::Windows;

    auto joined = join("C:\\Users\\", "\\gaspard", options);
    assert_true(static_cast<bool>(joined), "join should succeed for Windows paths.");
    assert_equal(joined.value(), "C:\\Users\\gaspard", "join should use Windows separators.");
  }

  void test_normalize_posix()
  {
    using namespace vix::path;

    PathOptions options;
    options.style = PathStyle::Posix;

    auto normalized = normalize("/a//b/./c/../d", options);
    assert_true(static_cast<bool>(normalized), "normalize should succeed for POSIX path.");
    assert_equal(normalized.value(), "/a/b/d", "normalize should collapse separators and dot segments.");
  }

  void test_normalize_windows()
  {
    using namespace vix::path;

    PathOptions options;
    options.style = PathStyle::Windows;

    auto normalized = normalize("C:\\temp\\\\foo\\.\\bar\\..\\file.txt", options);
    assert_true(static_cast<bool>(normalized), "normalize should succeed for Windows path.");
    assert_equal(normalized.value(), "C:\\temp\\foo\\file.txt", "normalize should preserve Windows style.");
  }

  void test_is_absolute_and_relative()
  {
    using namespace vix::path;

    assert_true(is_absolute("/usr/bin", PathStyle::Posix), "POSIX absolute path should be detected.");
    assert_true(!is_absolute("usr/bin", PathStyle::Posix), "POSIX relative path should not be absolute.");
    assert_true(is_relative("usr/bin", PathStyle::Posix), "POSIX relative path should be detected.");

    assert_true(is_absolute("C:\\Windows", PathStyle::Windows), "Windows drive absolute path should be detected.");
    assert_true(is_absolute("\\\\server\\share", PathStyle::Windows), "UNC path should be detected as absolute.");
    assert_true(!is_absolute("docs\\readme.md", PathStyle::Windows), "Windows relative path should not be absolute.");
    assert_true(is_relative("docs\\readme.md", PathStyle::Windows), "Windows relative path should be detected.");
  }

  void test_filename_parent_stem_extension()
  {
    using namespace vix::path;

    auto name = filename("/home/user/main.cpp");
    assert_true(static_cast<bool>(name), "filename should succeed.");
    assert_equal(name.value(), "main.cpp", "filename should extract last component.");

    auto par = parent("/home/user/main.cpp");
    assert_true(static_cast<bool>(par), "parent should succeed.");
    assert_equal(par.value(), "/home/user", "parent should return containing directory.");

    auto st = stem("/home/user/main.cpp");
    assert_true(static_cast<bool>(st), "stem should succeed.");
    assert_equal(st.value(), "main", "stem should remove final extension.");

    auto ext = extension("/home/user/main.cpp");
    assert_true(static_cast<bool>(ext), "extension should succeed.");
    assert_equal(ext.value(), ".cpp", "extension should include leading dot.");

    assert_true(has_extension("/home/user/main.cpp"), "has_extension should detect final extension.");
    assert_true(!has_extension("/home/user/Makefile"), "has_extension should return false when no extension exists.");
  }

  void test_replace_extension()
  {
    using namespace vix::path;

    auto replaced = replace_extension("/home/user/main.cpp", ".hpp");
    assert_true(static_cast<bool>(replaced), "replace_extension should succeed.");
    assert_equal(replaced.value(), "/home/user/main.hpp", "replace_extension should replace existing extension.");

    auto appended = replace_extension("/home/user/Makefile", "txt");
    assert_true(static_cast<bool>(appended), "replace_extension should append extension when missing.");
    assert_equal(appended.value(), "/home/user/Makefile.txt", "replace_extension should append normalized extension.");
  }

  void test_basename_dirname()
  {
    using namespace vix::path;

    auto base = basename("/var/log/system.log");
    assert_true(static_cast<bool>(base), "basename should succeed.");
    assert_equal(base.value(), "system.log", "basename should match filename.");

    auto dir = dirname("/var/log/system.log");
    assert_true(static_cast<bool>(dir), "dirname should succeed.");
    assert_equal(dir.value(), "/var/log", "dirname should match parent.");
  }

  void test_split()
  {
    using namespace vix::path;

    auto parts = split("/home/user/main.cpp");
    assert_true(static_cast<bool>(parts), "split should succeed.");

    assert_equal(parts.value().root, "/", "split should detect POSIX root.");
    assert_equal(parts.value().dirname, "/home/user", "split should compute dirname.");
    assert_equal(parts.value().filename, "main.cpp", "split should compute filename.");
    assert_equal(parts.value().stem, "main", "split should compute stem.");
    assert_equal(parts.value().extension, ".cpp", "split should compute extension.");
  }

  void test_lexically_normal()
  {
    using namespace vix::path;

    PathOptions options;
    options.style = PathStyle::Posix;

    auto normal = lexically_normal("/x//y/./z/../a", options);
    assert_true(static_cast<bool>(normal), "lexically_normal should succeed.");
    assert_equal(normal.value(), "/x/y/a", "lexically_normal should delegate to normalization.");
  }

  void test_lexically_relative()
  {
    using namespace vix::path;

    PathOptions options;
    options.style = PathStyle::Posix;

    auto rel = lexically_relative("/a/b/c/file.txt", "/a/b/d", options);
    assert_true(static_cast<bool>(rel), "lexically_relative should succeed for compatible POSIX roots.");
    assert_equal(rel.value(), "../c/file.txt", "lexically_relative should compute lexical relative path.");
  }

  void test_lexically_proximate()
  {
    using namespace vix::path;

    PathOptions options;
    options.style = PathStyle::Windows;

    auto prox = lexically_proximate("D:\\docs\\file.txt", "C:\\base", options);
    assert_true(static_cast<bool>(prox), "lexically_proximate should succeed.");
    assert_equal(prox.value(), "D:\\docs\\file.txt", "lexically_proximate should return normalized target when roots differ.");
  }

  void test_absolute_and_relative_high_level()
  {
    using namespace vix::path;

    PathOptions options;
    options.style = PathStyle::Posix;

    auto abs = absolute("docs/readme.md", "/home/gaspard", options);
    assert_true(static_cast<bool>(abs), "absolute should resolve relative path against absolute base.");
    assert_equal(abs.value(), "/home/gaspard/docs/readme.md", "absolute should join base and relative path.");

    auto rel = relative("/home/gaspard/docs/readme.md", "/home/gaspard", options);
    assert_true(static_cast<bool>(rel), "relative should succeed.");
    assert_equal(rel.value(), "docs/readme.md", "relative should compute high-level lexical relative path.");
  }

  void test_errors()
  {
    using namespace vix::path;

    auto r1 = normalize("", {});
    assert_true(!r1, "normalize should fail on empty path.");

    auto r2 = absolute("docs/file.txt", "", {});
    assert_true(!r2, "absolute should fail when resolving relative path with empty base.");

    auto r3 = split("");
    assert_true(!r3, "split should fail on empty path.");
  }

} // namespace

int main()
{
  test_separator_helpers();
  test_join_posix();
  test_join_windows();
  test_normalize_posix();
  test_normalize_windows();
  test_is_absolute_and_relative();
  test_filename_parent_stem_extension();
  test_replace_extension();
  test_basename_dirname();
  test_split();
  test_lexically_normal();
  test_lexically_relative();
  test_lexically_proximate();
  test_absolute_and_relative_high_level();
  test_errors();

  std::cout << "[PASS] vix_path_test\n";
  return EXIT_SUCCESS;
}
