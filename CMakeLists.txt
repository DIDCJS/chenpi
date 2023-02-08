cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(chenpi VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB_RECURSE SRC_FILES "engine/src/*.cpp" "engine/src/conpoment/*.cpp")
file(GLOB_RECURSE INCLUDE_FILES "engine/include/*.h" "engine/include/conpoment/*.h")
# file(GLOB_RECURSE INCLUDE_FILES "*.cpp")

message("### ${SRC_FILES}")
message("### ${INCLUDE_FILES}")

add_executable(chenpi ${SRC_FILES} ${INCLUDE_FILE} main.cpp)

target_include_directories(chenpi PUBLIC 
    engine/include)   

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
