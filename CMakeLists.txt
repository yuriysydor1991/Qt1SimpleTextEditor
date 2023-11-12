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
        QT_HTML_DEALER "QtHtmlDealerMocPreprocessingCustomTarget"
        CACHE STRING "Qt Html dealer custom moc preprocessor stage target name"
)
set(
        QT_WINDOW_LIB_TARGET "QtWindowLibraryTarget"
        CACHE STRING "Qt window target object file library target"
)
set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}" CACHE STRING "Doxygen documentation output if any.")
set(DOXYGEN_TAB_SIZE "2" CACHE STRING "Doxygen documentation tab size if any.")
set(DOXYGEN_INLINE_SOURCES "YES" CACHE STRING "Include source code into doxygen documentaiton if any.")
set(
        DOXYGEN_CONF_OUTPUT "${CMAKE_BINARY_DIR}/Doxygen"
        CACHE STRING "Doxygen documentation output configure file if any."
)
set(
        DOXYGEN_CONF_INPUT "${CMAKE_SOURCE_DIR}/Doxygen.in"
        CACHE STRING "Doxygen documentation input configure file if any."
)
set(RESOURCES_DIR "${CMAKE_SOURCE_DIR}/resources" CACHE STRING "Directory with additional project resources.")
set(LUPDATE_PRO_IN "${CMAKE_SOURCE_DIR}/src/lupdate.pro.in" CACHE STRING "Qt5 Linguist's lupdate tool project file configure input")
set(LUPDATE_PRO "${CMAKE_BINARY_DIR}/lupdate.pro" CACHE STRING "Qt5 Linguist's lupdate tool project file")
set(UA_TRANSLATION_TS "${RESOURCES_DIR}/Qt1SimpleTextEditorDemo_uk_UA.ts" CACHE STRING "Ukrainian TS translation file.")
set(UA_TRANSLATION_QM "${RESOURCES_DIR}/Qt1SimpleTextEditorDemo_uk_UA.qm" CACHE STRING "Ukrainian TS translation file.")
set(QM_TARGET "generate-QM-files" CACHE STRING "Qt qm binary translation file target")
set(ALL_TRANSLATION_FILES "${UA_TRANSLATION_TS}" CACHE STRING "All dest TS files to generate")
set(EDITOR_CREATOR_NAME "Yuriy Sydor")
set(PROJECT_CREATOR_EMAIL "yuriysydor1991@gmail.com")
set(PROJECT_GIT_URL "https://github.com/yuriysydor1991/Qt1SimpleTextEditor")

# Thanks for
# https://stackoverflow.com/questions/71762846/set-cmake-project-description-with-commit-id
# page for git commit id code.
find_package(Git REQUIRED)
execute_process(
        COMMAND "${GIT_EXECUTABLE}" rev-parse HEAD
        OUTPUT_VARIABLE PROJECT_GIT_COMMIT
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

string(TIMESTAMP PROJECT_BUILD_DATE "%Y-%m-%d %H:%M:%S %Z")

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
