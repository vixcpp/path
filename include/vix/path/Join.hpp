/**
 *
 *  @file Join.hpp
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
#ifndef VIX_PATH_JOIN_HPP
#define VIX_PATH_JOIN_HPP

#include <string_view>

#include <vix/path/PathResult.hpp>

namespace vix::path
{

  /**
   * @brief Join two path fragments using lexical rules.
   *
   * This function is multi-platform and uses the preferred separator
   * from the provided options.
   */
  [[nodiscard]] PathResult join(std::string_view left,
                                std::string_view right,
                                const PathOptions &options = {});

  /**
   * @brief Join three path fragments using lexical rules.
   */
  [[nodiscard]] PathResult join(std::string_view a,
                                std::string_view b,
                                std::string_view c,
                                const PathOptions &options = {});

} // namespace vix::path

#endif // VIX_PATH_JOIN_HPP
