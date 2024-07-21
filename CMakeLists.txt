# CMakeList.txt : CMake project for maya, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.30)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("maya")

# TODO remove hardcoded paths
include_directories(c:/db/libs/raylib/build/raylib/include c:/db/libs/raygui/src)

set(RAYLIB_DEBUG c:/db/libs/raylib/build/raylib/Debug/raylib.lib)
set(RAYLIB_RELEASE c:/db/libs/raylib/build/raylib/Release/raylib.lib)
set(GLFW_DEBUG C:/db/libs/raylib/build/raylib/external/glfw/src/Debug/glfw3.lib)
set(GLFW_RELEASE C:/db/libs/raylib/build/raylib/external/glfw/src/Release/glfw3.lib)

set(ICON_SOURCE "${CMAKE_SOURCE_DIR}/assets/icons/icon.png")
set(ICON_DESTINATION "${CMAKE_BINARY_DIR}/assets/icons")

# Ensure the destination directory exists
file(MAKE_DIRECTORY ${ICON_DESTINATION})

# Copy the icon to the destination directory
file(COPY ${ICON_SOURCE} DESTINATION ${ICON_DESTINATION})


add_executable (maya "maya.cpp")

target_sources(maya PRIVATE FILE_SET CXX_MODULES FILES "renderer.ixx" "window.ixx")

# TODO look into why winmm is needed (not multiplatform).
target_link_libraries(${PROJECT_NAME} debug ${RAYLIB_DEBUG} winmm.lib optimized ${RAYLIB_RELEASE} winmm.lib)


