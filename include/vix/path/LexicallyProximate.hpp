/**
 *
 *  @file LexicallyProximate.hpp
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
#ifndef VIX_PATH_LEXICALLYPROXIMATE_HPP
#define VIX_PATH_LEXICALLYPROXIMATE_HPP

#include <string_view>

#include <vix/path/PathResult.hpp>

namespace vix::path
{

  /**
   * @brief Compute a lexical relative path when possible, otherwise return target.
   *
   * This mirrors the common "proximate" behavior:
   * - if a lexical relative path can be computed, return it
   * - otherwise return the normalized target path
   */
  [[nodiscard]] PathResult lexically_proximate(std::string_view target,
                                               std::string_view base,
                                               const PathOptions &options = {});

} // namespace vix::path

#endif // VIX_PATH_LEXICALLYPROXIMATE_HPP
