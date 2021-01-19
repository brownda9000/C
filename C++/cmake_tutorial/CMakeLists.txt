cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  MESSAGE("Clang")
  set(CMAKE_C_COMPILER clang)
  #Link Time Optimization.
  set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-fuse-ld=lld -flto=full")
  # -fprofile-use
  # Compiler Options
  #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftime-trace -ftime-report -fprofile-generate -Wall -Wno-sign-compare -fsanitize=address -fsanitize=memory -fsanitize=undefined -fsanitize=thread -fstack-protector -fstack-protector-strong -fstack-protector-all -fsanitize=safe-stack -fsanitize=cfi")
  SET(CMAKE_AR ${CMAKE_CXX_COMPILER_AR} CACHE PATH "AR" FORCE)
  SET(CMAKE_RANLIB ${CMAKE_CXX_COMPILER_RANLIB} CACHE PATH "RANLIB" FORCE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fprofile-arcs -ftest-coverage -fPIC  -ftime-trace -flto -ftime-report -Wall -Wno-sign-compare -fsanitize=address -fsanitize=undefined  -fstack-protector -fstack-protector-strong -fstack-protector-all -fsanitize=cfi -fvisibility=hidden")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  MESSAGE("GNU")
  message("Building with lcov Code Coverage Tool -->")
  #add_compile_options("--coverage -fprofile-arcs -ftest-coverage")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fsanitize=address -static-libasan  -Werror -O0 -Wextra -Wall -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -ggdb3 -g  -Wall -Wextra -pedantic --coverage -fprofile-arcs -ftest-coverage")
  #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fdiagnostics-path-format=separate-events -fsanitize=address -static-libasan   -fanalyzer  -Werror -O0 -Wextra -Wall -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -ggdb3 -g -fanalyzer -fdiagnostics-path-format=separate-events -Wall -Wextra -pedantic --coverage -fprofile-arcs -ftest-coverage")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  MESSAGE("Intel")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  MESSAGE("MSVC")
endif()


# specify the C++ standard
option(USE_CLANG "build application with clang" OFF) # OFF is the default
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_CXX_FLAGS_COVERAGE "-g -O0 --coverage")



#set(CMAKE_CXX_FLAGS_COVERAGE "-Wall -Wextra -pedantic -Werror -fprofile-arcs -ftest-coverage")
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
#    add_compile_options(-Wall -Wextra -pedantic -Werror -fprofile-arcs -ftest-coverage)
endif()


# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# configure a header file to pass the version number only
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the MathFunctions library
add_subdirectory(MathFunctions)

# add the executable
add_executable(Tutorial tutorial.cxx)
#find_program(iwyu_path NAMES include-what-you-use iwyu)
#if(NOT iwyu_path)
#  message(FATAL_ERROR "Could not find the program include-what-you-use")
#endif()

#set_property(TARGET Tutorial PROPERTY CXX_INCLUDE_WHAT_YOU_USE ${iwyu_path})

#SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
#SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

target_link_libraries(Tutorial PUBLIC MathFunctions)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# add the install targets
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  DESTINATION include
  )

LIST(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")
#include(gcovr)

# enable testing
include(CTest)

# does the application run
add_test(NAME Runs COMMAND Tutorial 25)

# does the usage message work?
add_test(NAME Usage COMMAND Tutorial)
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
  )

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# do a bunch of result based tests
do_test(Tutorial 4 "4 is 2")
do_test(Tutorial 9 "9 is 3")
do_test(Tutorial 5 "5 is 2.236")
do_test(Tutorial 7 "7 is 2.645")
do_test(Tutorial 25 "25 is 5")
do_test(Tutorial -25 "-25 is [-nan|nan|0]")
do_test(Tutorial 0.0001 "0.0001 is 0.01")


# Include extra CMake files that are used for testing and linting.
#include(${CMAKE_SOURCE_DIR}/cmake/unit_test.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/clang_tools.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/gcovr.cmake)
#include(${CMAKE_SOURCE_DIR}/cmake/cppcheck.cmake)


include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)
