/**
 *
 *  @file LexicallyNormal.cpp
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

#include <vix/path/LexicallyNormal.hpp>
#include <vix/path/Normalize.hpp>

namespace vix::path
{

  PathResult lexically_normal(std::string_view path, const PathOptions &options)
  {
    return normalize(path, options);
  }

} // namespace vix::path
