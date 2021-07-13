cmake_minimum_required(VERSION 3.0.0)
project(chenpi VERSION 0.1.0)

SET(LIB_PATH lib)
SET(GLFW_PATH ${LIB_PATH}/glfw-3.3.4.bin.MACOS)

# include(CTest)
# enable_testing()

set (CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE CPP_FILES main.cpp 
							${LIB_PATH}/glad/src/glad.c
							src/engine/effect/*.cpp
							src/engine/*.cpp
							src/render/*.cpp)

add_executable(chenpi ${CPP_FILES})

# message(
# 	"###"..
# 	${CPP_FILES}
# )

# HEADER
INCLUDE_DIRECTORIES(
	${GLFW_PATH}/include
	${LIB_PATH}/glad/include
	src

)

message(${GLFW_PATH})

#lib

file(GLOB_RECURSE GLEW_LIB ${GLFW_PATH}/lib-x86_64/libglfw.3.dylib)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${GLEW_LIB})
# target_link_libraries(${PROJECT_NAME} OpenGL::GL)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
