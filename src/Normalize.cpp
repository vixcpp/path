/**
 *
 *  @file Normalize.cpp
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

#include <vix/path/Normalize.hpp>
#include <vix/path/PathError.hpp>
#include <vix/path/Separator.hpp>

namespace vix::path
{

  namespace
  {
    struct ParsedRoot
    {
      std::string root;
      std::size_t index{0};
      bool absolute{false};
    };

    [[nodiscard]] bool is_alpha_ascii(char c) noexcept
    {
      return std::isalpha(static_cast<unsigned char>(c)) != 0;
    }

    [[nodiscard]] ParsedRoot parse_root(std::string_view path, PathStyle style)
    {
      ParsedRoot out{};

      const auto use_windows =
          (style == PathStyle::Windows)
#ifdef _WIN32
          || (style == PathStyle::Native)
#endif
          ;

      if (path.empty())
      {
        return out;
      }

      if (use_windows)
      {
        if (path.size() >= 2 && is_alpha_ascii(path[0]) && path[1] == ':')
        {
          out.root = std::string(path.substr(0, 2));
          out.index = 2;

          if (path.size() > 2 && is_separator(path[2]))
          {
            out.root += '\\';
            out.index = 3;
            out.absolute = true;
          }

          return out;
        }

        if (path.size() >= 2 && is_separator(path[0]) && is_separator(path[1]))
        {
          out.root = "\\\\";
          out.index = 2;
          out.absolute = true;
          return out;
        }
      }

      if (is_separator(path.front()))
      {
        out.root = std::string(1, preferred_separator(style));
        out.index = 1;
        out.absolute = true;
      }

      return out;
    }

    [[nodiscard]] std::vector<std::string> split_segments(std::string_view path, std::size_t start)
    {
      std::vector<std::string> segments;
      std::size_t i = start;

      while (i < path.size())
      {
        while (i < path.size() && is_separator(path[i]))
        {
          ++i;
        }

        if (i >= path.size())
        {
          break;
        }

        std::size_t j = i;
        while (j < path.size() && !is_separator(path[j]))
        {
          ++j;
        }

        segments.emplace_back(path.substr(i, j - i));
        i = j;
      }

      return segments;
    }

    [[nodiscard]] std::string rebuild_path(const ParsedRoot &root,
                                           const std::vector<std::string> &segments,
                                           bool preserve_trailing_separator,
                                           char sep)
    {
      std::string out = root.root;

      bool need_sep_after_root = !out.empty() && !is_separator(out.back());

      for (std::size_t i = 0; i < segments.size(); ++i)
      {
        if (!out.empty() && (need_sep_after_root || !is_separator(out.back())))
        {
          out += sep;
        }

        out += segments[i];
        need_sep_after_root = true;
      }

      if (out.empty() && root.absolute)
      {
        out += sep;
      }

      if (preserve_trailing_separator && !out.empty() && !is_separator(out.back()))
      {
        out += sep;
      }

      return out;
    }
  } // namespace

  PathResult normalize(std::string_view path, const PathOptions &options)
  {
    if (path.empty())
    {
      return make_path_error(PathErrorCode::EmptyPath, "path cannot be empty");
    }

    const char sep = preferred_separator(options.style);
    const ParsedRoot root = parse_root(path, options.style);
    const bool had_trailing_separator = has_trailing_separator(path);

    std::vector<std::string> raw_segments = split_segments(path, root.index);
    std::vector<std::string> normalized;
    normalized.reserve(raw_segments.size());

    for (const auto &segment : raw_segments)
    {
      if (segment.empty())
      {
        continue;
      }

      if (segment == ".")
      {
        if (!options.remove_dot_segments)
        {
          normalized.push_back(segment);
        }
        continue;
      }

      if (segment == "..")
      {
        if (!options.resolve_dot_dot_segments)
        {
          normalized.push_back(segment);
          continue;
        }

        if (!normalized.empty() && normalized.back() != "..")
        {
          normalized.pop_back();
          continue;
        }

        if (root.absolute)
        {
          return make_path_error(
              PathErrorCode::TraversalAboveRoot,
              "path traversal above root is not allowed");
        }

        normalized.push_back(segment);
        continue;
      }

      normalized.push_back(segment);
    }

    const bool preserve_trailing_separator =
        options.preserve_trailing_separator && had_trailing_separator;

    return rebuild_path(root, normalized, preserve_trailing_separator, sep);
  }

} // namespace vix::path
