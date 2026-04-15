/**
 *
 *  @file ReplaceExtension.cpp
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

#include <vix/path/ReplaceExtension.hpp>
#include <vix/path/PathError.hpp>
#include <vix/path/Separator.hpp>

namespace vix::path
{

  PathResult replace_extension(std::string_view path, std::string_view new_extension)
  {
    if (path.empty())
    {
      return make_path_error(PathErrorCode::EmptyPath, "path cannot be empty");
    }

    std::string out(path);

    std::size_t end = out.size();
    while (end > 0 && is_separator(out[end - 1]))
    {
      --end;
    }

    const std::size_t last_sep = out.substr(0, end).find_last_of("/\\");
    const std::size_t last_dot = out.substr(0, end).rfind('.');

    const bool has_real_extension =
        last_dot != std::string::npos &&
        last_dot != 0 &&
        (last_sep == std::string::npos || last_dot > last_sep + 0);

    if (has_real_extension)
    {
      out.erase(last_dot, end - last_dot);
    }

    if (!new_extension.empty())
    {
      if (new_extension.front() != '.')
      {
        out += '.';
      }
      out += std::string(new_extension);
    }

    return out;
  }

} // namespace vix::path
