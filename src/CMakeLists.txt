cmake_minimum_required(VERSION 3.20)
project(SiftLibrary LANGUAGES CXX)

option(SIFT_BUILD_SHARED "Build SiftLog as a shared library" ON)

if (NOT DEFINED SIFT_INSTALL_DIR)
    set(SIFT_INSTALL_DIR "${CMAKE_BINARY_DIR}/install")
endif ()

set(SIFT_SOURCES
        log_searcher_factory.cpp
)

set(SIFT_HEADERS
        ${CMAKE_SOURCE_DIR}/interfaces/ILogSearcher.h
)

if (SIFT_BUILD_SHARED)
    add_library(siftlog SHARED ${SIFT_HEADERS} ${SIFT_SOURCES})
else ()
    add_library(siftlog STATIC ${SIFT_HEADERS} ${SIFT_SOURCES})
endif ()

set_target_properties(siftlog PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(siftlog PUBLIC ${CMAKE_SOURCE_DIR}/interfaces)

install(TARGETS siftlog
        RUNTIME DESTINATION ${SIFT_INSTALL_DIR}/bin
        LIBRARY DESTINATION ${SIFT_INSTALL_DIR}/lib
        ARCHIVE DESTINATION ${SIFT_INSTALL_DIR}/lib
        PUBLIC_HEADER DESTINATION ${SIFT_INSTALL_DIR}/include
)

if (WIN32)
    target_compile_definitions(siftlog PRIVATE SIFT_PLATFORM_WINDOWS)
    elif(APPLE)
    target_compile_definitions(siftlog PRIVATE SIFT_PLATFORM_MACOS)
    elif(UNIX)
    target_compile_definitions(siftlog PRIVATE SIFT_PLATFORM_LINUX)
endif ()

message(STATUS "SiftLog library configured and added to project")