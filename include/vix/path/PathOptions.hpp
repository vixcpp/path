/**
 *
 *  @file PathOptions.hpp
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
#ifndef VIX_PATH_PATHOPTIONS_HPP
#define VIX_PATH_PATHOPTIONS_HPP

namespace vix::path
{

  /**
   * @enum PathStyle
   * @brief Path syntax style to use when transforming or normalizing paths.
   */
  enum class PathStyle
  {
    Native,
    Posix,
    Windows
  };

  /**
   * @struct PathOptions
   * @brief Common options controlling lexical path transformations.
   *
   * These options are intentionally simple so they can be reused by most
   * path operations in the module.
   */
  struct PathOptions
  {
    /**
     * @brief Preferred path style.
     */
    PathStyle style{PathStyle::Native};

    /**
     * @brief Whether repeated separators should be collapsed.
     *
     * Example:
     * `foo//bar///baz` -> `foo/bar/baz`
     */
    bool collapse_separators{true};

    /**
     * @brief Whether `.` path segments should be removed.
     */
    bool remove_dot_segments{true};

    /**
     * @brief Whether `..` path segments should be resolved lexically when possible.
     */
    bool resolve_dot_dot_segments{true};

    /**
     * @brief Whether a trailing separator should be preserved.
     */
    bool preserve_trailing_separator{false};
  };

} // namespace vix::path

#endif // VIX_PATH_PATHOPTIONS_HPP
