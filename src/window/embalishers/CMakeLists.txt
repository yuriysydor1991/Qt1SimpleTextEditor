
target_sources(
        ${QT_WINDOW_LIB_TARGET}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/MenuEmbalisher.cpp
)

target_include_directories(
        ${QT_WINDOW_LIB_TARGET}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)