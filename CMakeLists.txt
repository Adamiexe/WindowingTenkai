cmake_minimum_required(VERSION 3.20)
project(WindowingTenkai LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CPM.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT TARGET glfw)
    add_subdirectory(libraries/glfw)
endif()

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "source/src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "source/include/*.h")
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/source/include
)

if(TARGET glfw)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
else()
    message(FATAL_ERROR "Erreur : GLFW n'a pas pu être configuré par CPM.")
endif()