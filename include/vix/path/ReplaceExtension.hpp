/**
 *
 *  @file ReplaceExtension.hpp
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
#ifndef VIX_PATH_REPLACEEXTENSION_HPP
#define VIX_PATH_REPLACEEXTENSION_HPP

#include <string_view>

#include <vix/path/PathResult.hpp>

namespace vix::path
{

  /**
   * @brief Replace the final extension of a path.
   *
   * If the path has no extension, the new extension is appended.
   * If new_extension is non-empty and does not start with '.', one is added.
   */
  [[nodiscard]] PathResult replace_extension(std::string_view path,
                                             std::string_view new_extension);

} // namespace vix::path

#endif // VIX_PATH_REPLACEEXTENSION_HPP
