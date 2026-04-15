add_executable(vix_path_test
  path_test.cpp
)

target_compile_features(vix_path_test PRIVATE cxx_std_20)

target_link_libraries(vix_path_test
  PRIVATE
    vix::path
)

add_test(NAME vix_path_test COMMAND vix_path_test)
