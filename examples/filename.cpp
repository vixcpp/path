/**
 *
 *  @file filename.cpp
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

#include <vix/path/Extension.hpp>
#include <vix/path/Filename.hpp>
#include <vix/path/Stem.hpp>

int main()
{
  const std::string path = "/home/gaspard/main.cpp";

  auto file = vix::path::filename(path);
  auto st = vix::path::stem(path);
  auto ext = vix::path::extension(path);

  if (!file)
  {
    std::cerr << "error: " << file.error().message() << '\n';
    return 1;
  }

  if (!st)
  {
    std::cerr << "error: " << st.error().message() << '\n';
    return 1;
  }

  if (!ext)
  {
    std::cerr << "error: " << ext.error().message() << '\n';
    return 1;
  }

  std::cout << "filename: " << file.value() << '\n';
  std::cout << "stem: " << st.value() << '\n';
  std::cout << "extension: " << ext.value() << '\n';

  return 0;
}
