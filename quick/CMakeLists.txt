project(quick CXX)

include_directories(AFTER
    src
    ${SOURCES_ROOT_DIR}
    ${INCLUDE_DIR}
)


if(WIN32)
    file(GLOB_RECURSE LOCAL_HEADERS "src/*.h")
    set(HEADERSFILE LOCAL_HEADERS )
endif() 

file(GLOB_RECURSE LOCAL_SRC "src/*.cpp")
set(SRCFILE ${LOCAL_SRC} )

source_group( all FILES 
    ${SRCFILE}
    ${HEADERSFILE}
)

add_executable(quick
    ${SRCFILE}
)

#target_link_libraries(quick libs)

install_targets(/bin quick)
#install_files(/include/subdir FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/file.h)
