/**
 *
 *  @file Parent.cpp
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

#include <vix/path/Parent.hpp>
#include <vix/path/PathError.hpp>
#include <vix/path/Separator.hpp>

namespace vix::path
{

  PathResult parent(std::string_view path)
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
      return std::string{};
    }

    if (pos == 0)
    {
      return std::string(path.substr(0, 1));
    }

    if (pos == 2 &&
        path.size() >= 2 &&
        ((path[1] == ':') || (path.size() > 2 && path[0] == '\\' && path[1] == '\\')))
    {
      return std::string(path.substr(0, pos + 1));
    }

    return std::string(path.substr(0, pos));
  }

} // namespace vix::path
