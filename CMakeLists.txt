cmake_minimum_required(VERSION 3.0.0)
project(chenpi VERSION 0.1.0)

SET(LIB_PATH lib)

# include(CTest)
# enable_testing()

file(GLOB_RECURSE CPP_FILES main.cpp 
							${LIB_PATH}/glad/src/glad.c
							src/engine/effect/*.cpp
							src/engine/*.cpp)

add_executable(chenpi ${CPP_FILES})

# HEADER
INCLUDE_DIRECTORIES(
	${LIB_PATH}/glfw-3.3.4.bin.WIN64/glfw-3.3.4.bin.WIN64/include
	${LIB_PATH}/glad/include
	src

)

#lib
TARGET_LINK_LIBRARIES(${PROJECT_NAME}  D:/.Project/chenpi/lib/glfw-3.3.4.bin.WIN64/glfw-3.3.4.bin.WIN64/lib-vc2019/glfw3.lib)
# target_link_libraries(${PROJECT_NAME} OpenGL::GL)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
