set(BORNAGAIN_ARCHITECTURE linux)
set(BORNAGAIN_PLATFORM linux)



execute_process(COMMAND uname -m OUTPUT_VARIABLE SYSCTL_OUTPUT)
if(${SYSCTL_OUTPUT} MATCHES x86_64)
    message(STATUS "Found a 64bit system")
    set(BIT_ENVIRONMENT "-m64")
    set(BORNAGAIN_ARCHITECTURE linuxx8664)
else()
    message(STATUS "Found a 32bit system")
    set(BIT_ENVIRONMENT "-m32")
    add_definitions(-DEIGEN_DONT_ALIGN_STATICALLY=1)
endif()

set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
set(CMAKE_CXX_FLAGS_RELEASE        "-O3")
set(CMAKE_CXX_FLAGS_DEBUG          "-g")
set(CMAKE_C_FLAGS_RELWITHDEBINFO   "-O3 -g")
set(CMAKE_C_FLAGS_RELEASE          "-O2")
set(CMAKE_C_FLAGS_DEBUG            "-g")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${CMAKE_SOURCE_DIR}/Core/Tools/inc -include WinDllMacros.h")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe ${BIT_ENVIRONMENT} -Wall -W -Woverloaded-virtual -fPIC")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe ${BIT_ENVIRONMENT} -Wall -W -fPIC")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")
