/**
 *
 *  @file Extension.hpp
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
#ifndef VIX_PATH_EXTENSION_HPP
#define VIX_PATH_EXTENSION_HPP

#include <string_view>

#include <vix/path/PathResult.hpp>

namespace vix::path
{

  /**
   * @brief Return the final extension of a path, including the leading dot.
   *
   * Returns an empty string if there is no extension.
   */
  [[nodiscard]] PathResult extension(std::string_view path);

} // namespace vix::path

#endif // VIX_PATH_EXTENSION_HPP
