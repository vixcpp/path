/**
 *
 *  @file HasExtension.cpp
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

#include <vix/path/HasExtension.hpp>
#include <vix/path/Filename.hpp>

namespace vix::path
{

  bool has_extension(std::string_view path) noexcept
  {
    auto name = filename(path);
    if (!name)
    {
      return false;
    }

    const std::string &file = name.value();
    if (file.empty() || file == "." || file == "..")
    {
      return false;
    }

    const std::size_t pos = file.rfind('.');
    return pos != std::string::npos && pos != 0;
  }

} // namespace vix::path
