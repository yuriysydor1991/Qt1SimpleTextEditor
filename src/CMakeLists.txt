cmake_minimum_required(VERSION 3.16.3)

find_program(
        CLANG_FORMAT_EXEC
        clang-format
)

if (CLANG_FORMAT_EXEC)
    file (GLOB_RECURSE ALLSOURCES LIST_DIRECTORIES false "*.h" "*.cpp")

    message(STATUS "All the sources: " ${ALLSOURCES})

    add_custom_target (
            clang-format
            COMMAND ${CLANG_FORMAT_EXEC} -style=file --verbose -i ${ALLSOURCES}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
else()
    message(WARNING
            "No clang-format executable or style file found.\n"
            "No code formatting target defined."
    )
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)

get_target_property(Qt5Includes Qt5::Widgets INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(Qt5CoreIncludes Qt5::Core INTERFACE_INCLUDE_DIRECTORIES)

add_executable(
        ${PROJECT_NAME}
        main.cpp
        window/WindowFactory.cpp
        window/file-dealers/TxtDealer.cpp
        window/file-dealers/FileDealer.cpp
        window/file-dealers/FilterCreator.cpp
        window/file-dealers/DealersFactory.cpp
        window/embellishers/MenuEmbellisher.cpp
)

include_directories(
        ${Qt5Includes} ${Qt5CoreIncludes} window window/file-dealers window/embellishers
)

add_compile_options(
        -Wall
        -pedantic
)

add_dependencies(
        ${PROJECT_NAME}
        ${QT_WINDOW_LIB_TARGET}
)

target_link_libraries(
        ${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        $<TARGET_OBJECTS:${QT_WINDOW_LIB_TARGET}>
)

add_subdirectory(window)
