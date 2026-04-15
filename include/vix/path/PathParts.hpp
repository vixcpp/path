/**
 *
 *  @file PathParts.hpp
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
#ifndef VIX_PATH_PATHPARTS_HPP
#define VIX_PATH_PATHPARTS_HPP

#include <string>

namespace vix::path
{

  /**
   * @struct PathParts
   * @brief Structured decomposition of a path.
   *
   * PathParts is useful for APIs such as `split()`, debugging,
   * and tools that need a stable decomposition of a path string.
   */
  struct PathParts
  {
    /**
     * @brief Root portion of the path.
     *
     * Examples:
     * - `/`
     * - `C:`
     * - `\\server\share`
     */
    std::string root;

    /**
     * @brief Directory portion without the final filename.
     */
    std::string dirname;

    /**
     * @brief Final filename portion.
     *
     * Example:
     * `main.cpp`
     */
    std::string filename;

    /**
     * @brief Filename without extension.
     *
     * Example:
     * `main`
     */
    std::string stem;

    /**
     * @brief File extension including the leading dot when present.
     *
     * Example:
     * `.cpp`
     */
    std::string extension;
  };

} // namespace vix::path

#endif // VIX_PATH_PATHPARTS_HPP
