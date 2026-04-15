/**
 *
 *  @file Normalize.hpp
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
#ifndef VIX_PATH_NORMALIZE_HPP
#define VIX_PATH_NORMALIZE_HPP

#include <string_view>

#include <vix/path/PathResult.hpp>

namespace vix::path
{

  /**
   * @brief Normalize a path lexically.
   *
   * Normalization may:
   * - unify separators
   * - collapse repeated separators
   * - remove `.` segments
   * - resolve `..` segments when possible
   *
   * This function is purely lexical and does not query the filesystem.
   */
  [[nodiscard]] PathResult normalize(std::string_view path,
                                     const PathOptions &options = {});

} // namespace vix::path

#endif // VIX_PATH_NORMALIZE_HPP
