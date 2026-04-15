/**
 *
 *  @file normalize.cpp
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

#include <vix/path/Normalize.hpp>
#include <vix/path/PathOptions.hpp>

int main()
{
  vix::path::PathOptions options;
  options.style = vix::path::PathStyle::Posix;

  auto result = vix::path::normalize("/home//gaspard/./projects/../vix", options);

  if (!result)
  {
    std::cerr << "error: " << result.error().message() << '\n';
    return 1;
  }

  std::cout << "normalized path: " << result.value() << '\n';
  return 0;
}
