/**
 *
 *  @file Basename.hpp
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
#ifndef VIX_PATH_BASENAME_HPP
#define VIX_PATH_BASENAME_HPP

#include <string_view>

#include <vix/path/PathResult.hpp>

namespace vix::path
{

  /**
   * @brief Return the basename of a path.
   *
   * In this module, basename is equivalent to filename.
   */
  [[nodiscard]] PathResult basename(std::string_view path);

} // namespace vix::path

#endif // VIX_PATH_BASENAME_HPP
