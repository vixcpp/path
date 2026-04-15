/**
 *
 *  @file LexicallyNormal.hpp
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
#ifndef VIX_PATH_LEXICALLYNORMAL_HPP
#define VIX_PATH_LEXICALLYNORMAL_HPP

#include <string_view>

#include <vix/path/PathResult.hpp>

namespace vix::path
{

  /**
   * @brief Return the lexically normal form of a path.
   *
   * This is the canonical lexical normalization entry point of the module.
   * It does not access the filesystem.
   */
  [[nodiscard]] PathResult lexically_normal(std::string_view path,
                                            const PathOptions &options = {});

} // namespace vix::path

#endif // VIX_PATH_LEXICALLYNORMAL_HPP
