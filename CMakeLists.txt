cmake_minimum_required(VERSION 3.5)
project(LabTools VERSION 0.0.1 DESCRIPTION "STUFF" LANGUAGES CXX)

add_executable(LabTools src/main.cpp src/lab.cpp src/term_util.cpp)
target_compile_features(LabTools PRIVATE cxx_std_17)
target_include_directories(LabTools PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

make_directory(res)

add_custom_command(
        TARGET LabTools POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/res/t.cpp
                ${CMAKE_CURRENT_BINARY_DIR}/res/t.cpp)