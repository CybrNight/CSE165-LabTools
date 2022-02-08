cmake_minimum_required(VERSION 3.15)
project(LabTools VERSION 0.0.1 DESCRIPTION "STUFF" LANGUAGES CXX)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/lab.cpp src/term_util.cpp)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc/)

set(INST_DIR inst/)
set(RES_DIR res/)


#Copy resources to build dir
make_directory(${RES_DIR})

add_custom_command(
        TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/res/t.cpp
                ${CMAKE_CURRENT_BINARY_DIR}/res/t.cpp)


install (TARGETS ${CMAKE_PROJECT_NAME} DESTINATION ${INST_DIR})
install (DIRECTORY ${RES_DIR} DESTINATION ${INST_DIR}/res/)