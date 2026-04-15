/**
 *
 *  @file Relative.cpp
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

#include <vix/path/LexicallyRelative.hpp>
#include <vix/path/Relative.hpp>

namespace vix::path
{

  PathResult relative(std::string_view target,
                      std::string_view base,
                      const PathOptions &options)
  {
    return lexically_relative(target, base, options);
  }

} // namespace vix::path
