/**
 *
 *  @file Filename.hpp
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
#ifndef VIX_PATH_FILENAME_HPP
#define VIX_PATH_FILENAME_HPP

#include <string_view>

#include <vix/path/PathResult.hpp>

namespace vix::path
{

  /**
   * @brief Return the final filename component of a path.
   *
   * This function is purely lexical and does not access the filesystem.
   */
  [[nodiscard]] PathResult filename(std::string_view path);

} // namespace vix::path

#endif // VIX_PATH_FILENAME_HPP
