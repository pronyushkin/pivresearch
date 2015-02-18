project(pivtests CXX)

include_directories(AFTER
    src
    ${SOURCES_ROOT_DIR}
    ${INCLUDE_DIR}
)


if(WIN32)
    set(HEADERSFILE src/sort/check.h )
endif() 


set(SRCFILE
	src/main.cpp
        src/sort/check.cpp
        src/sort/bubble.cpp
)

source_group( all FILES 
    ${SRCFILE}
    ${HEADERSFILE}
)

add_executable(pivtests
    ${SRCFILE}
    ${HEADERSFILE}
)

install_targets(/bin pivtests)
