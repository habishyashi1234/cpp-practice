cmake_minimum_required(VERSION 3.10)
project(CppTaskManager)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES src/main.cpp src/Task.cpp src/TaskManager.cpp)

include_directories(include)

add_executable(CppTaskManager ${SOURCE_FILES})