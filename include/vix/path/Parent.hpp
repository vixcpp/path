/**
 *
 *  @file Parent.hpp
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
#ifndef VIX_PATH_PARENT_HPP
#define VIX_PATH_PARENT_HPP

#include <string_view>

#include <vix/path/PathResult.hpp>

namespace vix::path
{

  /**
   * @brief Return the parent path of a given path.
   *
   * This function is purely lexical and does not access the filesystem.
   */
  [[nodiscard]] PathResult parent(std::string_view path);

} // namespace vix::path

#endif // VIX_PATH_PARENT_HPP
