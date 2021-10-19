cmake_minimum_required(VERSION 3.0)

project(dds_image LANGUAGES CXX)

add_library(dds_image INTERFACE)
target_include_directories(dds_image INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/)
