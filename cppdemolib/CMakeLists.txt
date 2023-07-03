cmake_minimum_required(VERSION 3.24)

project(cppdemolib)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Build shared (dynamic) libraries." ON)
option(ENABLE_TESTING "Enable a Unit Testing build." ON)


enable_testing()

add_library(cppdemolib SHARED src/cppdemolib_api.cpp)
target_include_directories(cppdemolib PUBLIC include)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(cppdemolib PRIVATE fmt::fmt)
target_compile_definitions(cppdemolib PRIVATE CPPDEMOLIB_EXPORTS)
#add_subdirectory(test)


# 查找并链接 Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
# 添加测试目标
add_executable(mylibrary_test test/test_hello.cpp)
target_link_libraries(mylibrary_test ${GTEST_LIBRARIES} cppdemolib)

# 添加测试
add_test(NAME mylibrary_test COMMAND mylibrary_test)
