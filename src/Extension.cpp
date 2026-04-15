/**
 *
 *  @file Extension.cpp
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

#include <vix/path/Extension.hpp>
#include <vix/path/Filename.hpp>

namespace vix::path
{

  PathResult extension(std::string_view path)
  {
    auto name = filename(path);
    if (!name)
    {
      return name.error();
    }

    const std::string &file = name.value();
    if (file.empty() || file == "." || file == "..")
    {
      return std::string{};
    }

    const std::size_t pos = file.rfind('.');
    if (pos == std::string::npos || pos == 0)
    {
      return std::string{};
    }

    return file.substr(pos);
  }

} // namespace vix::path
