cmake_minimum_required(VERSION 3.16.3)

configure_file(
        Qt1SimpleTextEditor-conf.h.in
        ${CMAKE_BINARY_DIR}/Qt1SimpleTextEditor-conf.h
)

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

# for doxygen documentation generation
# not required to build the project
# Doc output directory under CMAKE_BINARY_DIR
find_program(
        DOXYGEN_EXEC
        doxygen
)

find_program(
        GRAPHIZ_DOT_EXEC
        dot
)

if (DOXYGEN_EXEC AND GRAPHIZ_DOT_EXEC)
    message(STATUS "Doxygen: " ${DOXYGEN_EXEC})
    message(STATUS "Doxygen input configure file: " ${DOXYGEN_CONF_INPUT})
    message(STATUS "Doxygen configure file: " ${DOXYGEN_CONF_OUTPUT})

    configure_file(
            ${DOXYGEN_CONF_INPUT}
            ${DOXYGEN_CONF_OUTPUT}
    )

    add_custom_target (
            Doxygen-doc
            COMMAND ${DOXYGEN_EXEC} ${DOXYGEN_CONF_OUTPUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
else()
    message(WARNING
            "No doxygen or graphiz' dot executable found.\n"
            "No code documentation generation target will be declared.\n"
            "if you want to generate documentation, please, install doxygen and graphviz by a command:\n"
            "sudo apt-get install -y doxygen graphviz"
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
