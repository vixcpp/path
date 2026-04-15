/**
 *
 *  @file Separator.hpp
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
#ifndef VIX_PATH_SEPARATOR_HPP
#define VIX_PATH_SEPARATOR_HPP

#include <string_view>

#include <vix/path/PathOptions.hpp>

namespace vix::path
{

  /**
   * @brief Return the preferred separator for a given path style.
   *
   * For `Native`, the result depends on the current platform.
   */
  [[nodiscard]] char preferred_separator(PathStyle style = PathStyle::Native) noexcept;

  /**
   * @brief Return true if c is a recognized path separator.
   *
   * On all platforms, both '/' and '\\' are treated as separators
   * for lexical path processing.
   */
  [[nodiscard]] constexpr bool is_separator(char c) noexcept
  {
    return c == '/' || c == '\\';
  }

  /**
   * @brief Return true if the path starts with a separator.
   */
  [[nodiscard]] bool has_leading_separator(std::string_view path) noexcept;

  /**
   * @brief Return true if the path ends with a separator.
   */
  [[nodiscard]] bool has_trailing_separator(std::string_view path) noexcept;

} // namespace vix::path

#endif // VIX_PATH_SEPARATOR_HPP
