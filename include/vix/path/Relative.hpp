/**
 *
 *  @file Relative.hpp
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
#ifndef VIX_PATH_RELATIVE_HPP
#define VIX_PATH_RELATIVE_HPP

#include <string_view>

#include <vix/path/PathOptions.hpp>
#include <vix/path/PathResult.hpp>

namespace vix::path
{

  /**
   * @brief Compute a lexical relative path from base to target.
   *
   * This is the high-level relative path API of the module.
   * It does not access the filesystem.
   */
  [[nodiscard]] PathResult relative(std::string_view target,
                                    std::string_view base,
                                    const PathOptions &options = {});

} // namespace vix::path

#endif // VIX_PATH_RELATIVE_HPP
