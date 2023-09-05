cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)
set(
        PROJECT_NAME "Qt1SimpleTextEditorDemo"
        CACHE STRING "Project general name with a executable name"
)
set(
        QT_WINDOW_TARGET "QtWindowMocPreprocessingCustomTarget"
        CACHE STRING "Qt window custom moc preprocessor stage target name"
)
set(
        QT_WINDOW_LIB_TARGET "QtWindowLibraryTarget"
        CACHE STRING "Qt window target object file library target"
)

message(STATUS "PROJECT_NAME: ${PROJECT_NAME}")

project(
        ${PROJECT_NAME}
        VERSION 1.0.0
        LANGUAGES CXX
)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)

get_target_property(Qt5Includes Qt5::Widgets INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(Qt5IncludesCore Qt5::Core INTERFACE_INCLUDE_DIRECTORIES)

message(STATUS "Qt5Includes: ${Qt5Includes}")
message(STATUS "Qt5IncludesCore: ${Qt5IncludesCore}")

add_executable(
        ${PROJECT_NAME}
        src/main.cpp
)

add_compile_options(
        -Wall
        -Werror
        -pedantic
)

include_directories(
        ${CMAKE_SOURCE_DIR}/src
        ${Qt5Includes}
        ${Qt5IncludesCore}
)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/window)

add_dependencies(
        Qt1SimpleTextEditorDemo
        ${QT_WINDOW_LIB_TARGET}
)

target_link_libraries(Qt1SimpleTextEditorDemo Qt5::Widgets $<TARGET_OBJECTS:${QT_WINDOW_LIB_TARGET}>)
