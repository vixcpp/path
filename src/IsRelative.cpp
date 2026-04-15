/**
 *
 *  @file IsRelative.cpp
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

#include <vix/path/IsRelative.hpp>
#include <vix/path/IsAbsolute.hpp>

namespace vix::path
{

  bool is_relative(std::string_view path, PathStyle style) noexcept
  {
    return !is_absolute(path, style);
  }

} // namespace vix::path
