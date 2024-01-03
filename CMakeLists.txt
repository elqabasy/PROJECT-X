# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(PROJECT-X)

# Add the executable and source files
add_executable(PROJECT-X
    main.cpp
    src/drawings.cpp
    src/getpass.cpp
    src/loginSys.cpp
    src/File.cpp
    src/Formatting.cpp
    # ... add more source files as needed
)

# Include directories
target_include_directories(PROJECT-X PRIVATE include)

# Optional: Specify C++ standard
set_property(TARGET PROJECT-X PROPERTY CXX_STANDARD 11)