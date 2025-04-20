cmake_minimum_required(VERSION 3.10.0)
project(iterators VERSION 0.1.0 LANGUAGES CXX)

add_executable(iterators main.cpp)

target_compile_features(iterators PUBLIC cxx_std_23)

