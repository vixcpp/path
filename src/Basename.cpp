/**
 *
 *  @file Basename.cpp
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

#include <vix/path/Basename.hpp>
#include <vix/path/Filename.hpp>

namespace vix::path
{

  PathResult basename(std::string_view path)
  {
    return filename(path);
  }

} // namespace vix::path
