/**
 *
 *  @file IsAbsolute.cpp
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

#include <vix/path/IsAbsolute.hpp>
#include <vix/path/Separator.hpp>

namespace vix::path
{

  namespace
  {
    [[nodiscard]] bool is_alpha_ascii(char c) noexcept
    {
      return std::isalpha(static_cast<unsigned char>(c)) != 0;
    }
  } // namespace

  bool is_absolute(std::string_view path, PathStyle style) noexcept
  {
    if (path.empty())
    {
      return false;
    }

    const auto use_windows =
        (style == PathStyle::Windows)
#ifdef _WIN32
        || (style == PathStyle::Native)
#endif
        ;

    if (use_windows)
    {
      if (path.size() >= 3 &&
          is_alpha_ascii(path[0]) &&
          path[1] == ':' &&
          is_separator(path[2]))
      {
        return true;
      }

      if (path.size() >= 2 && is_separator(path[0]) && is_separator(path[1]))
      {
        return true;
      }
    }

    return is_separator(path.front());
  }

} // namespace vix::path
