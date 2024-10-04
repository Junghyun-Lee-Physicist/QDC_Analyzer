# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(ParticleLab_Analyzer)

# Set C++ standard to C++17 to match ROOT requirements
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the ROOT package
find_package(ROOT REQUIRED)

# Include ROOT headers
include_directories(${ROOT_INCLUDE_DIRS})
include_directories(include)

# Add executable
add_executable(ParticleLab_Analyzer ParticleLab_Analyzer.cpp src/EventLooper.cpp)

# Link against ROOT libraries
target_link_libraries(ParticleLab_Analyzer ${ROOT_LIBRARIES})
