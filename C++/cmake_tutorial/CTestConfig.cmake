set(CTEST_PROJECT_NAME "CMakeTutorial")
set(CTEST_NIGHTLY_START_TIME "00:00:00 EST")

##############################################################
set(CTEST_SOURCE_DIRECTORY "$ENV{HOME}/C++/cmake_tutorial")
set(CTEST_BINARY_DIRECTORY "$ENV{HOME}/C++/cmake_tutorial/build")
## which ctest command to use for running the dashboard
set(CTEST_COMMAND
  "/usr/bin/ctest  -D Nightly"
  )

# what cmake command to use for configuring this dashboard
set(CTEST_CMAKE_COMMAND
  "/usr/bin/cmake"
  )

set(CTEST_BUILD_NAME "linux-gcc-default")
#
set(CTEST_CMAKE_GENERATOR "Unix Makefiles")
set(CTEST_BUILD_CONFIGURATION "Profiling")
#set(CTEST_BUILD_OPTIONS "-DWITH_SSH1=ON -WITH_SFTP=ON -DWITH_SERVER=ON -DWITH_ZLIB=ON -DWITH_PCAP=ON -DWITH_GCRYPT=OFF")
#
#set(WITH_MEMCHECK TRUE)
#set(WITH_COVERAGE TRUE)
#
#find_program(CTEST_GIT_COMMAND NAMES git)
find_program(CTEST_COVERAGE_COMMAND NAMES gcovr)
#find_program(CTEST_MEMORYCHECK_COMMAND NAMES valgrind)
#
#set(CTEST_MEMORYCHECK_SUPPRESSIONS_FILE ${CTEST_SOURCE_DIRECTORY}/build/Testing/valgrind.supp)
#
##ctest_coverage()
##ctest_memcheck()
#############################################

set(CTEST_DROP_METHOD "http")
set(CTEST_DROP_SITE "my.cdash.org")
set(CTEST_DROP_LOCATION "/submit.php?project=CMakeTutorial")
set(CTEST_DROP_SITE_CDASH TRUE)