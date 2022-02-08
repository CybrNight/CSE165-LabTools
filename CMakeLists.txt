cmake_minimum_required(VERSION 3.18)
project(LabTools VERSION 0.4 DESCRIPTION "STUFF" LANGUAGES CXX)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY LabTools)
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
    set(ARCHIVE LabTools-Mac.zip)
endif()

if (WIN32)
    set(ARCHIVE LabTools-Windows.zip)
endif()

make_directory(${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/lab.cpp src/term_util.cpp)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc/)

#Copy res dir to bin folder
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} PRE_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${CMAKE_SOURCE_DIR}/res/ ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/res/)

#Compress built executable
if (LINUX)
    add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
                        COMMAND ${CMAKE_COMMAND} -E tar "cfvz" 
                        ../${ARCHIVE} * WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
else()
    add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
                        COMMAND ${CMAKE_COMMAND} -E tar "cfv" 
                        ../${ARCHIVE} --format=zip * WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()

install (FILES build/${ARCHIVE} DESTINATION ${INST_DIR})