/**
 *
 *  @file Absolute.hpp
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
#ifndef VIX_PATH_ABSOLUTE_HPP
#define VIX_PATH_ABSOLUTE_HPP

#include <string_view>

#include <vix/path/PathOptions.hpp>
#include <vix/path/PathResult.hpp>

namespace vix::path
{

  /**
   * @brief Resolve a path to an absolute lexical path using a base path.
   *
   * Rules:
   * - if path is already absolute, it is normalized and returned
   * - if path is relative, it is joined with base and normalized
   *
   * This function does not access the filesystem.
   */
  [[nodiscard]] PathResult absolute(std::string_view path,
                                    std::string_view base,
                                    const PathOptions &options = {});

} // namespace vix::path

#endif // VIX_PATH_ABSOLUTE_HPP
