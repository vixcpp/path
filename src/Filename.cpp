/**
 *
 *  @file Filename.cpp
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

#include <string>

#include <vix/path/Filename.hpp>
#include <vix/path/PathError.hpp>
#include <vix/path/Separator.hpp>

namespace vix::path
{

  PathResult filename(std::string_view path)
  {
    if (path.empty())
    {
      return make_path_error(PathErrorCode::EmptyPath, "path cannot be empty");
    }

    std::size_t end = path.size();
    while (end > 0 && is_separator(path[end - 1]))
    {
      --end;
    }

    if (end == 0)
    {
      return std::string{};
    }

    const std::size_t pos = path.substr(0, end).find_last_of("/\\");
    if (pos == std::string_view::npos)
    {
      return std::string(path.substr(0, end));
    }

    return std::string(path.substr(pos + 1, end - (pos + 1)));
  }

} // namespace vix::path
