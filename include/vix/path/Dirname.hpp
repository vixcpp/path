/**
 *
 *  @file Dirname.hpp
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
#ifndef VIX_PATH_DIRNAME_HPP
#define VIX_PATH_DIRNAME_HPP

#include <string_view>

#include <vix/path/PathResult.hpp>

namespace vix::path
{

  /**
   * @brief Return the directory portion of a path.
   *
   * In this module, dirname is equivalent to parent.
   */
  [[nodiscard]] PathResult dirname(std::string_view path);

} // namespace vix::path

#endif // VIX_PATH_DIRNAME_HPP
