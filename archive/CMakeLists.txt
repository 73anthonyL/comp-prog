cmake_minimum_required(VERSION 3.8)
project(anthony)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Globbing for source files
file(GLOB_RECURSE sources "${CMAKE_SOURCE_DIR}/*.cpp")

# Print the source files found
message(STATUS "Source files: ${sources}")

# Exclude unwanted directories (like .vscode) from the sources list
foreach(file ${sources})
    if(file MATCHES ".vscode")
        list(REMOVE_ITEM sources ${file})
    endif()
endforeach()

# Check if any sources were found
if(NOT sources)
    message(FATAL_ERROR "No source files found. Ensure you have .cpp files in the src directory.")
endif()

# Create executable
add_executable(anthony ${sources})

# Add include directories
target_include_directories(anthony PUBLIC 
    "${CMAKE_SOURCE_DIR}/include"
    "/opt/homebrew/Cellar/gcc/14.1.0_1/include/c++/14/"
    "/opt/homebrew/Cellar/gcc/14.1.0_1/include/c++/14/aarch64-apple-darwin23"
)

# Link with GCC libraries if necessary
target_link_libraries(anthony PRIVATE stdc++)
