cmake_minimum_required(VERSION 3.20)
project(WindowingTenkai LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CPM.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT glfw_ADDED)
    CPMAddPackage(
        NAME glfw
        GITHUB_REPOSITORY glfw/glfw
        GIT_TAG 3.4
        SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libraries/glfw"
    )
endif()

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "source/src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "source/include/*.h")
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/source/include
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries/glfw/include
)

find_package(glfw3 QUIET CONFIG)
if(NOT glfw3_FOUND)
    find_package(GLFW3 QUIET)
endif()

if(TARGET glfw3::glfw)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw3::glfw)
elseif(TARGET glfw)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
elseif(glfw3_FOUND)
    if(DEFINED GLFW3_LIBRARIES)
        target_link_libraries(${PROJECT_NAME} PRIVATE ${GLFW3_LIBRARIES})
    endif()
else()
    message(STATUS "GLFW not found..")
endif()