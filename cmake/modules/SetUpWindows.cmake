if(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
  set(BORNAGAIN_ARCHITECTURE win64)
  set(BORNAGAIN_PLATFORM win64)
else()
    set(BORNAGAIN_ARCHITECTURE win32)
    set(BORNAGAIN_PLATFORM win32)
endif()

add_definitions(-DEIGEN_DONT_ALIGN_STATICALLY=1)
message(STATUS "Disabling static align for Eigen")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP -nologo /EHsc /D_USE_MATH_DEFINES -I${CMAKE_SOURCE_DIR}/Core/Tools -FIw32pragma.h -FIWinDllMacros.h")
set(CMAKE_SHARED_LINKER_FLAGS "/NODEFAULTLIB:libcmtd.lib")
