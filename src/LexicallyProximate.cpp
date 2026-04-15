/**
 *
 *  @file LexicallyProximate.cpp
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

#include <vix/path/LexicallyProximate.hpp>
#include <vix/path/LexicallyRelative.hpp>
#include <vix/path/Normalize.hpp>

namespace vix::path
{

  PathResult lexically_proximate(std::string_view target,
                                 std::string_view base,
                                 const PathOptions &options)
  {
    auto rel = lexically_relative(target, base, options);
    if (rel)
    {
      return rel;
    }

    return normalize(target, options);
  }

} // namespace vix::path
