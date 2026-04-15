/**
 *
 *  @file Join.cpp
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

#include <string>

#include <vix/path/Join.hpp>
#include <vix/path/Normalize.hpp>
#include <vix/path/PathError.hpp>
#include <vix/path/Separator.hpp>

namespace vix::path
{

  namespace
  {
    [[nodiscard]] std::string trim_leading_separators(std::string_view s)
    {
      std::size_t i = 0;
      while (i < s.size() && is_separator(s[i]))
      {
        ++i;
      }
      return std::string(s.substr(i));
    }

    [[nodiscard]] std::string trim_trailing_separators(std::string_view s)
    {
      if (s.empty())
      {
        return {};
      }

      std::size_t end = s.size();
      while (end > 0 && is_separator(s[end - 1]))
      {
        --end;
      }
      return std::string(s.substr(0, end));
    }
  } // namespace

  PathResult join(std::string_view left,
                  std::string_view right,
                  const PathOptions &options)
  {
    if (left.empty() && right.empty())
    {
      return make_path_error(PathErrorCode::EmptyPath, "cannot join two empty paths");
    }

    if (left.empty())
    {
      return normalize(right, options);
    }

    if (right.empty())
    {
      return normalize(left, options);
    }

    const char sep = preferred_separator(options.style);

    std::string lhs = trim_trailing_separators(left);
    std::string rhs = trim_leading_separators(right);

    std::string joined;
    joined.reserve(lhs.size() + 1 + rhs.size());
    joined += lhs;
    joined += sep;
    joined += rhs;

    return normalize(joined, options);
  }

  PathResult join(std::string_view a,
                  std::string_view b,
                  std::string_view c,
                  const PathOptions &options)
  {
    auto ab = join(a, b, options);
    if (!ab)
    {
      return ab.error();
    }

    return join(ab.value(), c, options);
  }

} // namespace vix::path
