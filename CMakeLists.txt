cmake_minimum_required(VERSION 3.5)
project(LabTools VERSION 0.0.1 DESCRIPTION "STUFF" LANGUAGES CXX)

add_executable(LabToolsBinary src/main.cpp src/lab.cpp)
target_compile_features(LabToolsBinary PRIVATE cxx_std_17)
target_include_directories(LabToolsBinary PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)