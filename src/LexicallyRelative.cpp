/**
 *
 *  @file LexicallyRelative.cpp
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
#include <string_view>
#include <vector>

#include <vix/path/LexicallyRelative.hpp>
#include <vix/path/Normalize.hpp>
#include <vix/path/PathError.hpp>
#include <vix/path/Separator.hpp>

namespace vix::path
{

  namespace
  {
    struct ParsedPath
    {
      std::string root;
      std::vector<std::string> segments;
      bool absolute{false};
    };

    [[nodiscard]] bool is_alpha_ascii(char c) noexcept
    {
      return std::isalpha(static_cast<unsigned char>(c)) != 0;
    }

    [[nodiscard]] bool use_windows_rules(PathStyle style) noexcept
    {
      return style == PathStyle::Windows
#ifdef _WIN32
             || style == PathStyle::Native
#endif
          ;
    }

    [[nodiscard]] ParsedPath parse_path(std::string_view path, PathStyle style)
    {
      ParsedPath out{};

      const bool windows = use_windows_rules(style);

      std::size_t index = 0;

      if (path.empty())
      {
        return out;
      }

      if (windows)
      {
        if (path.size() >= 3 &&
            is_alpha_ascii(path[0]) &&
            path[1] == ':' &&
            is_separator(path[2]))
        {
          out.root = std::string(path.substr(0, 2));
          out.absolute = true;
          index = 3;
        }
        else if (path.size() >= 2 && is_separator(path[0]) && is_separator(path[1]))
        {
          out.root = "\\\\";
          out.absolute = true;
          index = 2;
        }
        else if (path.size() >= 2 &&
                 is_alpha_ascii(path[0]) &&
                 path[1] == ':')
        {
          out.root = std::string(path.substr(0, 2));
          out.absolute = false;
          index = 2;
        }
        else if (is_separator(path.front()))
        {
          out.root = std::string(1, preferred_separator(style));
          out.absolute = true;
          index = 1;
        }
      }
      else
      {
        if (is_separator(path.front()))
        {
          out.root = "/";
          out.absolute = true;
          index = 1;
        }
      }

      while (index < path.size())
      {
        while (index < path.size() && is_separator(path[index]))
        {
          ++index;
        }

        if (index >= path.size())
        {
          break;
        }

        std::size_t end = index;
        while (end < path.size() && !is_separator(path[end]))
        {
          ++end;
        }

        out.segments.emplace_back(path.substr(index, end - index));
        index = end;
      }

      return out;
    }

    [[nodiscard]] bool roots_equal(const ParsedPath &a, const ParsedPath &b, PathStyle style)
    {
      if (use_windows_rules(style))
      {
        if (a.root.size() == 2 && b.root.size() == 2 &&
            a.root[1] == ':' && b.root[1] == ':')
        {
          return std::tolower(static_cast<unsigned char>(a.root[0])) ==
                     std::tolower(static_cast<unsigned char>(b.root[0])) &&
                 a.root[1] == b.root[1];
        }
      }

      return a.root == b.root && a.absolute == b.absolute;
    }

    [[nodiscard]] std::string join_segments(const std::vector<std::string> &segments, char sep)
    {
      if (segments.empty())
      {
        return ".";
      }

      std::string out;
      for (std::size_t i = 0; i < segments.size(); ++i)
      {
        if (i != 0)
        {
          out += sep;
        }
        out += segments[i];
      }
      return out;
    }
  } // namespace

  PathResult lexically_relative(std::string_view target,
                                std::string_view base,
                                const PathOptions &options)
  {
    if (target.empty())
    {
      return make_path_error(PathErrorCode::EmptyPath, "target path cannot be empty");
    }

    if (base.empty())
    {
      return make_path_error(PathErrorCode::EmptyPath, "base path cannot be empty");
    }

    auto normalized_target = normalize(target, options);
    if (!normalized_target)
    {
      return normalized_target.error();
    }

    auto normalized_base = normalize(base, options);
    if (!normalized_base)
    {
      return normalized_base.error();
    }

    const ParsedPath t = parse_path(normalized_target.value(), options.style);
    const ParsedPath b = parse_path(normalized_base.value(), options.style);

    if (!roots_equal(t, b, options.style))
    {
      return make_path_error(
          PathErrorCode::IncompatibleRoots,
          "cannot compute lexical relative path between incompatible roots");
    }

    std::size_t common = 0;
    while (common < t.segments.size() &&
           common < b.segments.size() &&
           t.segments[common] == b.segments[common])
    {
      ++common;
    }

    std::vector<std::string> out_segments;

    for (std::size_t i = common; i < b.segments.size(); ++i)
    {
      out_segments.emplace_back("..");
    }

    for (std::size_t i = common; i < t.segments.size(); ++i)
    {
      out_segments.push_back(t.segments[i]);
    }

    return join_segments(out_segments, preferred_separator(options.style));
  }

} // namespace vix::path
