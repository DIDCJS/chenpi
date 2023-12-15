cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(chenpi VERSION 0.1.0)

# include(CTest)
# enable_testing()

set(THREE_PARTY_PATH "3rd")

file(GLOB_RECURSE SRC_FILES "engine/src/*.cpp" 
                    "engine/src/conpoment/*.cpp"
                    "engine/core/*.cpp"

                    "${THREE_PARTY_PATH}/imgui/imgui.cpp"
                    "${THREE_PARTY_PATH}/imgui/imgui_demo.cpp"
                    "${THREE_PARTY_PATH}/imgui/imgui_draw.cpp"
                    "${THREE_PARTY_PATH}/imgui/imgui_tables.cpp"
                    "${THREE_PARTY_PATH}/imgui/imgui_widgets.cpp"
                    "${THREE_PARTY_PATH}/imgui/backends/imgui_impl_glfw.cpp"
                    "${THREE_PARTY_PATH}/imgui/backends/imgui_impl_opengl3.cpp"
                    )
file(GLOB_RECURSE INCLUDE_FILES "engine/include/*.h" 
                            "engine/include/conpoment/*.h"
                            "engine/include/core/*.h"
                            )
# file(GLOB_RECURSE INCLUDE_FILES "*.cpp")

message("### ${SRC_FILES}")
message("### ${INCLUDE_FILES}")

add_executable(chenpi ${SRC_FILES} ${INCLUDE_FILES} main.cpp)

target_include_directories(chenpi PUBLIC 
    engine/include
    ${THREE_PARTY_PATH}/imgui
    ${THREE_PARTY_PATH}/imgui/backends
    )   

find_package(glfw3 REQUIRED)
# find_package(OpenGL REQUIRED)

target_link_libraries(chenpi glfw  "-framework OpenGL")



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
