/**
 *
 *  @file IsRelative.hpp
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
#ifndef VIX_PATH_ISRELATIVE_HPP
#define VIX_PATH_ISRELATIVE_HPP

#include <string_view>

#include <vix/path/PathOptions.hpp>

namespace vix::path
{

  /**
   * @brief Return true if the given path is lexically relative.
   */
  [[nodiscard]] bool is_relative(std::string_view path,
                                 PathStyle style = PathStyle::Native) noexcept;

} // namespace vix::path

#endif // VIX_PATH_ISRELATIVE_HPP
