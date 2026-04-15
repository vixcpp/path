/**
 *
 *  @file Absolute.cpp
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

#include <vix/path/Absolute.hpp>
#include <vix/path/IsAbsolute.hpp>
#include <vix/path/Join.hpp>
#include <vix/path/Normalize.hpp>
#include <vix/path/PathError.hpp>

namespace vix::path
{

  PathResult absolute(std::string_view path,
                      std::string_view base,
                      const PathOptions &options)
  {
    if (path.empty())
    {
      return make_path_error(PathErrorCode::EmptyPath, "path cannot be empty");
    }

    if (is_absolute(path, options.style))
    {
      return normalize(path, options);
    }

    if (base.empty())
    {
      return make_path_error(
          PathErrorCode::EmptyPath,
          "base path cannot be empty when resolving a relative path");
    }

    if (!is_absolute(base, options.style))
    {
      return make_path_error(
          PathErrorCode::InvalidPath,
          "base path must be absolute");
    }

    return join(base, path, options);
  }

} // namespace vix::path
