/**
 *
 *  @file Split.cpp
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

#include <cctype>
#include <string>

#include <vix/path/Dirname.hpp>
#include <vix/path/Extension.hpp>
#include <vix/path/Filename.hpp>
#include <vix/path/Parent.hpp>
#include <vix/path/PathError.hpp>
#include <vix/path/Split.hpp>
#include <vix/path/Stem.hpp>

namespace vix::path
{

  namespace
  {
    [[nodiscard]] bool is_alpha_ascii(char c) noexcept
    {
      return std::isalpha(static_cast<unsigned char>(c)) != 0;
    }

    [[nodiscard]] std::string detect_root(std::string_view path)
    {
      if (path.empty())
      {
        return {};
      }

      if (path.size() >= 3 &&
          is_alpha_ascii(path[0]) &&
          path[1] == ':' &&
          (path[2] == '/' || path[2] == '\\'))
      {
        return std::string(path.substr(0, 3));
      }

      if (path.size() >= 2 &&
          (path[0] == '/' || path[0] == '\\') &&
          (path[1] == '/' || path[1] == '\\'))
      {
        return "\\\\";
      }

      if (path[0] == '/' || path[0] == '\\')
      {
        return std::string(1, path[0]);
      }

      if (path.size() >= 2 && is_alpha_ascii(path[0]) && path[1] == ':')
      {
        return std::string(path.substr(0, 2));
      }

      return {};
    }
  } // namespace

  PathPartsResult split(std::string_view path)
  {
    if (path.empty())
    {
      return make_path_error(PathErrorCode::EmptyPath, "path cannot be empty");
    }

    auto dir = dirname(path);
    if (!dir)
    {
      return dir.error();
    }

    auto file = filename(path);
    if (!file)
    {
      return file.error();
    }

    auto st = stem(path);
    if (!st)
    {
      return st.error();
    }

    auto ext = extension(path);
    if (!ext)
    {
      return ext.error();
    }

    PathParts parts;
    parts.root = detect_root(path);
    parts.dirname = dir.value();
    parts.filename = file.value();
    parts.stem = st.value();
    parts.extension = ext.value();

    return parts;
  }

} // namespace vix::path
