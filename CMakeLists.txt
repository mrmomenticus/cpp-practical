cmake_minimum_required(VERSION 3.10.0)
project(iterators VERSION 0.1.0 LANGUAGES CXX)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(iterators iterators/iterators.cpp)

target_compile_features(iterators PUBLIC cxx_std_23)
target_link_libraries(iterators PRIVATE Catch2::Catch2WithMain)
