cmake_minimum_required(VERSION 2.8)

project(pivsearch CXX)

set(PROJECT_ROOT_DIR  ${CMAKE_CURRENT_SOURCE_DIR} )
message(STATUS "PROJECT_ROOT_DIR=${PROJECT_ROOT_DIR}" )


if(NOT DEFINED CONTRIB_DIR)
    set(CONTRIB_DIR          ${PROJECT_ROOT_DIR}/_contrib )
endif()
set(CONTRIB_INC_DIR      ${CONTRIB_DIR}/include         )
set(CONTRIB_LIB_DIR      ${CONTRIB_DIR}/lib             )

message(STATUS "CONTRIB_DIR=${CONTRIB_DIR}" )
message(STATUS "CONTRIB_INC_DIR=${CONTRIB_INC_DIR}" )
message(STATUS "CONTRIB_LIB_DIR=${CONTRIB_LIB_DIR}" )


if(NOT DEFINED OUTPUT_DIR)
    set(OUTPUT_DIR          ${PROJECT_ROOT_DIR}/_result  )
endif()
set(CMAKE_INSTALL_PREFIX ${OUTPUT_DIR})
message(STATUS "OUTPUT_DIR=${OUTPUT_DIR}" )


if(UNIX)
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
     set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -fPIC")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS On)

if(MSVC)
    # remove "Please define _WIN32_WINNT..."
    add_definitions(-D_WIN32_WINNT=0x0501)
endif()


#add_subdirectory(util)
add_subdirectory(test)
add_subdirectory(quick)
