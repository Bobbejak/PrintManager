cmake_minimum_required(VERSION 3.10)
project(PrintInterceptor)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find JNI
find_package(JNI REQUIRED)

# Include JNI headers
include_directories(${JNI_INCLUDE_DIRS})

# Add library
add_library(PrintInterceptorNative SHARED
    src/main/cpp/PrintInterceptorNative.cpp
)

# Link against JNI
target_link_libraries(PrintInterceptorNative ${JNI_LIBRARIES})