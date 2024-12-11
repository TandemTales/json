cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(json_standalone LANGUAGES CXX)

# --- Import tools ----
include(../cmake/tools.cmake)

# ---- Dependencies ----
include(../cmake/CPM.cmake)

CPMAddPackage(NAME json SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

# Add package: TandemTales/core
CPMAddPackage(
	NAME core
	GITHUB_REPOSITORY TandemTales/core
	#VERSION 1.1.0
	GIT_TAG main
)

# ---- Create standalone executable ----
file(GLOB sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

add_executable(${PROJECT_NAME} ${sources})

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:/MTd>
        $<$<CONFIG:Release>:/MT>
    )
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES 
    CXX_STANDARD 20
    OUTPUT_NAME "json"
)

target_link_libraries(${PROJECT_NAME} json core)

# This line will create a folder hierarchy in the Visual Studio solution explorer
# that matches the directory structure under ${CMAKE_CURRENT_SOURCE_DIR}/source.
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/source" FILES ${sources})
