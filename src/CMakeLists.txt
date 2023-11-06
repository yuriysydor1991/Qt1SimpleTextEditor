cmake_minimum_required(VERSION 3.26.4)

add_subdirectory(window)

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