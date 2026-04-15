/**
 *
 *  @file PathResult.hpp
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
#ifndef VIX_PATH_PATHRESULT_HPP
#define VIX_PATH_PATHRESULT_HPP

#include <string>
#include <vector>

#include <vix/error/Result.hpp>
#include <vix/path/PathParts.hpp>

namespace vix::path
{

  /**
   * @brief Standard result type for path operations returning a single path string.
   */
  using PathResult = vix::error::Result<std::string>;

  /**
   * @brief Standard result type for path operations returning multiple path segments.
   */
  using PathListResult = vix::error::Result<std::vector<std::string>>;

  /**
   * @brief Standard result type for path operations returning structured path parts.
   */
  using PathPartsResult = vix::error::Result<PathParts>;

} // namespace vix::path

#endif // VIX_PATH_PATHRESULT_HPP
