#################################################################################
#
#  BornAgain: simulate and fit scattering at grazing incidence
#
#  @file      cmake/bornagain/modules/GoogletestWrapper.cmake
#  @brief     Implements function WRAP_GTEST(..)
#
#  @homepage  http://www.bornagainproject.org
#  @license   GNU General Public License v3 or higher (see COPYING)
#  @copyright Forschungszentrum Jülich GmbH 2016
#  @authors   Scientific Computing Group at MLZ Garching
#  @authors   J. Fisher, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
#
##################################################################################

#  @brief Compile tests given as .h files in SUBDIR, link with LINK_LIB, and execute

#  STAGE=0: test run at compile time
#  STAGE=1: test run upon "ctest"="make check"

function(WRAP_GTEST TEST_NAME SUBDIR LINK_LIB STAGE)
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

    file(GLOB INCLUDE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${SUBDIR}/*.h")
    list(SORT INCLUDE_FILES)

    # Compose main program (C++ snippets plus #include's of test code from SUBDIR)
    set(TMP "/* Generated by CMake. Do not edit. Do not put under version control. */\n")
    file(READ "${TEMPLATE_DIR}/GoogletestHeader.cpp" TMPTMP)
    set(TMP "${TMP}\n${TMPTMP}\n")
    foreach(FILE ${INCLUDE_FILES})
        set(TMP "${TMP}#include \"${CMAKE_CURRENT_SOURCE_DIR}/${FILE}\"\n")
    endforeach()
    file(READ "${TEMPLATE_DIR}/GoogletestFooter.cpp" TMPTMP)
    set(TMP "${TMP}\n${TMPTMP}")

    set(TEST_SRC "${BUILD_AUTO_DIR}/${TEST_NAME}.cpp")
    file(WRITE ${TEST_SRC} "${TMP}")

    set(EXE ${TEST_NAME})
    add_executable(${EXE} ${TEST_SRC})
    target_link_libraries(${EXE} gtest ${LINK_LIB})

    # Build executable in lib directory,
    # to prevent problems with finding libBornAgainCore.dll under Windows
    # set_property(TARGET ${EXE} PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

    if    (${STAGE} EQUAL 0)
        # Add execution of TestCore just after compilation
        add_custom_command(TARGET ${TEST_NAME} POST_BUILD COMMAND ${EXE})
    elseif(${STAGE} EQUAL 1)
        add_test(${TEST_NAME} ${EXE})
    else()
        message(FATAL_ERROR "invalid parameter STAGE=${STAGE} in WRAP_GTEST")
    endif()

    # To make the .h files appear in QtCreator's project tree
    add_custom_target("${TEST_NAME}_sources" SOURCES ${INCLUDE_FILES})
endfunction()
