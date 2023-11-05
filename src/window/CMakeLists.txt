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
        COMMAND ${Qt5AUTOMOC_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/EditorWindow.h" -o EditorWindow.moc.h
        BYPRODUCTS ${CMAKE_CURRENT_BINARY_DIR}/EditorWindow.moc.h
        SOURCES EditorWindow.h
        COMMENT "QT5 window header moc preprocess command"
)

add_compile_options(
        -fPIC
)

add_library(
        ${QT_WINDOW_LIB_TARGET}
        OBJECT
        FilterCreator.cpp
        EditorWindow.cpp
        WindowFactory.cpp
)

target_include_directories(
        ${QT_WINDOW_LIB_TARGET}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
)

add_dependencies(
        ${QT_WINDOW_LIB_TARGET}
        ${QT_WINDOW_TARGET}
)

add_subdirectory(embellishers)
