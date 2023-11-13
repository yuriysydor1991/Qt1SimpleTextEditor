cmake_minimum_required(VERSION 3.16.3)

message(STATUS "QT_WINDOW_TARGET: ${QT_WINDOW_TARGET}")

find_program(
        Qt5AUTOMOC_EXECUTABLE
        moc
)

message(STATUS "Qt5AUTOMOC_EXECUTABLE: ${Qt5AUTOMOC_EXECUTABLE}")

if(NOT Qt5AUTOMOC_EXECUTABLE)
    message(FATAL_ERROR "No moc Qt5 executable found, please install Qt5 dev package")
endif()

add_custom_target(
        ${QT_WINDOW_TARGET}
        COMMAND ${Qt5AUTOMOC_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/EditorWindow.h" -o ${CMAKE_BINARY_DIR}/EditorWindow.moc.h
        BYPRODUCTS ${CMAKE_BINARY_DIR}/EditorWindow.moc.h
        SOURCES EditorWindow.h
        COMMENT "QT5 window header moc preprocess command"
)

add_custom_target(
        ${QT_HTML_DEALER}
        COMMAND ${Qt5AUTOMOC_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/file-dealers/HtmlDealer.h" -o ${CMAKE_BINARY_DIR}/HtmlDealer.moc.h
        BYPRODUCTS ${CMAKE_BINARY_DIR}/HtmlDealer.moc.h
        SOURCES file-dealers/HtmlDealer.h
        COMMENT "QT5 Html file dealer header moc preprocess command"
)

add_compile_options(
        -fPIC
)

add_library(
        ${QT_WINDOW_LIB_TARGET}
        OBJECT
        EditorWindow.cpp
        file-dealers/HtmlDealer.cpp
)

include_directories(
        ${QT_WINDOW_LIB_TARGET}
        ${Qt5GeneralIncludes} ${CMAKE_CURRENT_BINARY_DIR}
)

add_dependencies(
        ${QT_WINDOW_LIB_TARGET}
        ${QT_WINDOW_TARGET}
        ${QT_HTML_DEALER}
)
