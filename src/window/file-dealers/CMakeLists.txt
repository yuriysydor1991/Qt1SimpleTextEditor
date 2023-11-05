cmake_minimum_required(VERSION 3.26.4)

target_sources(
        ${QT_WINDOW_LIB_TARGET}
        PUBLIC TxtDealer.cpp FileDealer.cpp FilterCreator.cpp DealersFactory.cpp
)

target_include_directories(
        ${QT_WINDOW_LIB_TARGET}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
