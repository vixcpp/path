/**
 *
 *  @file Dirname.cpp
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

#include <vix/path/Dirname.hpp>
#include <vix/path/Parent.hpp>

namespace vix::path
{

  PathResult dirname(std::string_view path)
  {
    return parent(path);
  }

} // namespace vix::path
