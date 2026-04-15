/**
 *
 *  @file relative.cpp
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

#include <iostream>

#include <vix/path/PathOptions.hpp>
#include <vix/path/Relative.hpp>

int main()
{
  vix::path::PathOptions options;
  options.style = vix::path::PathStyle::Posix;

  auto result = vix::path::relative(
      "/home/gaspard/projects/vix/modules/path",
      "/home/gaspard/projects",
      options);

  if (!result)
  {
    std::cerr << "error: " << result.error().message() << '\n';
    return 1;
  }

  std::cout << "relative path: " << result.value() << '\n';
  return 0;
}
