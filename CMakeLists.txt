cmake_minimum_required(VERSION 3.16.3)

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
        DESCRIPTION "A simple Qt5 text editor for demonstration purposes"
        HOMEPAGE_URL "http://www.kytok.org.ua/"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
