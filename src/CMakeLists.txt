cmake_minimum_required(VERSION 3.16.3)

configure_file(
        window/Qt1SimpleTextEditor-conf.h.in
        ${CMAKE_BINARY_DIR}/Qt1SimpleTextEditor-conf.h
)

file(READ ${LOGO_FILEPATH} KYTOK_LOGO_DATA_HEX HEX)
file(SIZE ${LOGO_FILEPATH} KYTOK_LOGO_DATA_SIZE)
string(REGEX REPLACE "([0-9a-f][0-9a-f])" "0x\\1, "  KYTOK_LOGO_DATA_SINGLELINE ${KYTOK_LOGO_DATA_HEX})
string(REGEX REPLACE
        "(0x[0-9a-f][0-9a-f], 0x[0-9a-f][0-9a-f], 0x[0-9a-f][0-9a-f], 0x[0-9a-f][0-9a-f], 0x[0-9a-f][0-9a-f],) "
        "\t\t\\1\n"
        KYTOK_LOGO_DATA
        ${KYTOK_LOGO_DATA_SINGLELINE}
)


configure_file(
        window/kytok.org.ua-logo.h.in
        ${CMAKE_BINARY_DIR}/kytok.org.ua-logo.h
)

find_program(
        CLANG_FORMAT_EXEC
        clang-format
        clang-format.exe
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
        dot.exe
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
find_package(Qt5 COMPONENTS Gui REQUIRED)

get_target_property(Qt5Includes Qt5::Widgets INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(Qt5CoreIncludes Qt5::Core INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(Qt5GuiIncludes Qt5::Gui INTERFACE_INCLUDE_DIRECTORIES)

set(Qt5GeneralIncludes ${Qt5Includes} ${Qt5CoreIncludes} ${Qt5GuiIncludes})

add_executable(
        ${PROJECT_NAME}
        main.cpp
        window/WindowFactory.cpp
        window/file-dealers/TxtDealer.cpp
        window/file-dealers/FileDealer.cpp
        window/file-dealers/FilterCreator.cpp
        window/file-dealers/DealersFactory.cpp
        window/embellishers/MenuEmbellisher.cpp
        window/embellishers/AboutDialogEmbellisher.cpp
        window/embellishers/GoToLineEmbellisher.cpp
        window/embellishers/FindEmbellisher.cpp
        window/custom-widgets/TextEdit.cpp
)

include_directories(
        ${Qt5GeneralIncludes}
        window
        window/file-dealers
        window/embellishers
        window/custom-widgets
        ${CMAKE_BINARY_DIR}
)

add_compile_options(
        -Wall
        -pedantic
)

add_dependencies(
        ${PROJECT_NAME}
        ${QT_WINDOW_LIB_TARGET}
        ${QM_TARGET}
)

target_link_libraries(
        ${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        $<TARGET_OBJECTS:${QT_WINDOW_LIB_TARGET}>
)

add_subdirectory(window)

# cppcheck integration
find_program(CPPCHECK_EXEC cppcheck cppcheck.exe)

if (CPPCHECK_EXEC)
    message(STATUS "cppcheck: ${CPPCHECK_EXEC}")

    add_custom_target (
            unstable-cppcheck
            COMMAND ${CPPCHECK_EXEC} --std=c++${CMAKE_CXX_STANDARD} --inconclusive --enable=all -v
                ${Qt5GeneralIncludes}
                -Iwindow -Iwindow/file-dealers -Iwindow/embellishers -I${CMAKE_BINARY_DIR} -I${CMAKE_BINARY_DIR}/src/window
                ${CMAKE_CURRENT_SOURCE_DIR}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Executes cppcheck command for all project sources. Just outputs all findings into stdout."
    )
else()
    message(WARNING
            "No cppcheck executable found.\n"
            "No code check target will be declared.\n"
            "Install cppcheck by using command:\n"
            "sudo apt-get install -y cppcheck"
    )
endif()

# Qt linguist integration
find_program(LUPDATE_EXEC lupdate lupdate.exe)
find_program(LRELEASE_EXEC lrelease lrelease.exe)

if (LUPDATE_EXEC AND LRELEASE_EXEC)
    file(GLOB_RECURSE ALL_HEADERS_LIST LIST_DIRECTORIES false "*.h" "*.hpp" "*.H" "*.hxx")
    file(GLOB_RECURSE ALL_SOURCES_LIST LIST_DIRECTORIES false "*.cpp" "*.cxx" "*.C" "*.c++")

    list(JOIN ALL_HEADERS_LIST " " ALL_HEADERS)
    list(JOIN ALL_SOURCES_LIST " " ALL_SOURCES)

    configure_file(${LUPDATE_PRO_IN} ${LUPDATE_PRO})

    # to generate TS translation files
    # that can be used by the linguist command
    add_custom_target (
            generate-TS-files
            COMMAND ${LUPDATE_EXEC} -locations none -pro "${LUPDATE_PRO}" -tr-function-alias tr+=t
            COMMENT "Calls lupdate tool from Qt Linguist package to search for text string and generate TS file for future translation."
    )

    # to generate QM files
    add_custom_target (
            generate-QM-files
            COMMAND ${LRELEASE_EXEC} "${LUPDATE_PRO}"
            COMMENT "Calls lrelease tool from Qt Linguist package to generate all the QM files from TS files available."
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            DEPENDS generate-TS-files
    )
else()
    message(WARNING "Qt linguist's lupdate and/or lrelease tools were not found in the system. To install them run next command (Debian/Ubuntu):\n"
            "sudo apt-get install -y qttools5-dev-tools"
    )
endif()
