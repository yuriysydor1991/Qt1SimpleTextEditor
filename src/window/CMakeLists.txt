cmake_minimum_required(VERSION 3.16.3)

message(STATUS "QT_WINDOW_TARGET: ${QT_WINDOW_TARGET}")

execute_process (
        COMMAND which moc
        OUTPUT_VARIABLE Qt5AUTOMOC_EXECUTABLE
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

message(STATUS "Qt5AUTOMOC_EXECUTABLE: ${Qt5AUTOMOC_EXECUTABLE}")

add_custom_target(
        ${QT_WINDOW_TARGET}
        COMMAND ${Qt5AUTOMOC_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/window/EditorWindow.h" -o EditorWindow.moc.h
        BYPRODUCTS ${CMAKE_BINARY_DIR}/src/window/EditorWindow.moc.h
        SOURCES EditorWindow.h
        COMMENT "QT5 window header moc preprocess command"
)

add_compile_options(
        -I${CMAKE_BINARY_DIR}/src/window
        -fPIC
)

add_library(
        ${QT_WINDOW_LIB_TARGET}
        OBJECT
        EditorWindow.cpp
        WindowFactory.cpp
)

add_dependencies(
        ${QT_WINDOW_LIB_TARGET}
        ${QT_WINDOW_TARGET}
)
