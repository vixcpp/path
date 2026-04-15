/**
 *
 *  @file HasExtension.hpp
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
#ifndef VIX_PATH_HASEXTENSION_HPP
#define VIX_PATH_HASEXTENSION_HPP

#include <string_view>

namespace vix::path
{

  /**
   * @brief Return true if the path has a final extension.
   */
  [[nodiscard]] bool has_extension(std::string_view path) noexcept;

} // namespace vix::path

#endif // VIX_PATH_HASEXTENSION_HPP
