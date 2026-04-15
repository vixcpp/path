/**
 *
 *  @file PathError.hpp
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
#ifndef VIX_PATH_PATHERROR_HPP
#define VIX_PATH_PATHERROR_HPP

#include <string>

#include <vix/error/Error.hpp>
#include <vix/error/ErrorCategory.hpp>
#include <vix/error/ErrorCode.hpp>

namespace vix::path
{

  /**
   * @enum PathErrorCode
   * @brief Path-specific semantic error codes.
   *
   * These codes describe common lexical path failures.
   * They are intended to complement the generic Vix error model.
   */
  enum class PathErrorCode
  {
    None = 0,
    EmptyPath,
    InvalidPath,
    InvalidSegment,
    InvalidRoot,
    IncompatibleRoots,
    CannotComputeRelative,
    TraversalAboveRoot
  };

  /**
   * @brief Return the default path error category.
   */
  [[nodiscard]] inline constexpr vix::error::ErrorCategory path_error_category() noexcept
  {
    return vix::error::ErrorCategory("path");
  }

  /**
   * @brief Convert a PathErrorCode to a generic Vix ErrorCode.
   *
   * This allows the path module to integrate cleanly with the unified
   * Vix error system.
   */
  [[nodiscard]] inline constexpr vix::error::ErrorCode to_error_code(PathErrorCode code) noexcept
  {
    using vix::error::ErrorCode;

    switch (code)
    {
    case PathErrorCode::None:
      return ErrorCode::Ok;
    case PathErrorCode::EmptyPath:
    case PathErrorCode::InvalidPath:
    case PathErrorCode::InvalidSegment:
    case PathErrorCode::InvalidRoot:
    case PathErrorCode::IncompatibleRoots:
    case PathErrorCode::CannotComputeRelative:
    case PathErrorCode::TraversalAboveRoot:
      return ErrorCode::InvalidArgument;
    }

    return ErrorCode::InvalidArgument;
  }

  /**
   * @brief Convert a PathErrorCode to a human-readable name.
   */
  [[nodiscard]] inline const char *to_string(PathErrorCode code) noexcept
  {
    switch (code)
    {
    case PathErrorCode::None:
      return "none";
    case PathErrorCode::EmptyPath:
      return "empty_path";
    case PathErrorCode::InvalidPath:
      return "invalid_path";
    case PathErrorCode::InvalidSegment:
      return "invalid_segment";
    case PathErrorCode::InvalidRoot:
      return "invalid_root";
    case PathErrorCode::IncompatibleRoots:
      return "incompatible_roots";
    case PathErrorCode::CannotComputeRelative:
      return "cannot_compute_relative";
    case PathErrorCode::TraversalAboveRoot:
      return "traversal_above_root";
    }

    return "invalid_path";
  }

  /**
   * @brief Build a structured Vix error from a PathErrorCode.
   *
   * @param code Path-specific error code.
   * @param message Human-readable message.
   */
  [[nodiscard]] inline vix::error::Error make_path_error(PathErrorCode code, std::string message)
  {
    return vix::error::Error(
        to_error_code(code),
        path_error_category(),
        std::move(message));
  }

} // namespace vix::path

#endif // VIX_PATH_PATHERROR_HPP
