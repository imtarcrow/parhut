cmake_minimum_required(VERSION 3.31.10)

project("parhut" VERSION 0.0.1 LANGUAGES CXX)

message("Building in ${CMAKE_BUILD_TYPE} mode")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setup project files
set(SOURCES 
    src/main.cpp
    src/simulation.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ./include)

# Disable C++ Compiler extensions 
set_target_properties(${PROJECT_NAME} PROPERTIES
    C_EXTENSIONS OFF
    CXX_EXTENSIONS OFF
)

# Setup compiler settings
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
)
