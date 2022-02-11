cmake_minimum_required(VERSION 3.18)
project(LabTools VERSION 0.4 DESCRIPTION "STUFF" LANGUAGES CXX)
set(RES_DIR res)
set(INST_DIR instdir)

# Set install vars
if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if(LINUX)
    set(ARCHIVE LabTools-Ubuntu.tar.gz)
endif() 
    
if (APPLE)
    set(ARCHIVE LabTools-MacOS.tar.gz)
endif()

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/lab.cpp src/term_util.cpp src/files.cpp)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc/)

#Compress built executable

add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E tar "cfvz" 
                    ../${ARCHIVE} ${CMAKE_PROJECT_NAME})
