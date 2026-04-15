/**
 *
 *  @file Separator.cpp
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

#include <vix/path/Separator.hpp>

namespace vix::path
{

  char preferred_separator(PathStyle style) noexcept
  {
    switch (style)
    {
    case PathStyle::Posix:
      return '/';
    case PathStyle::Windows:
      return '\\';
    case PathStyle::Native:
#ifdef _WIN32
      return '\\';
#else
      return '/';
#endif
    }

#ifdef _WIN32
    return '\\';
#else
    return '/';
#endif
  }

  bool has_leading_separator(std::string_view path) noexcept
  {
    return !path.empty() && is_separator(path.front());
  }

  bool has_trailing_separator(std::string_view path) noexcept
  {
    return !path.empty() && is_separator(path.back());
  }

} // namespace vix::path
