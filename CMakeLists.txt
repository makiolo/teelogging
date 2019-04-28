project(teelogging CXX)
cmake_minimum_required(VERSION 3.5)
include("$ENV{CMAKI_PWD}/node_modules/npm-mas-mas/cmaki/cmaki.cmake")
cmaki_setup()
include_directories(include)
cmaki_library(teelogging src/teelogging_manager.cpp PTHREADS)
cmaki_google_test(test1 tests/test1.cpp DEPENDS teelogging PTHREADS)
cmaki_google_test(test2 tests/test2.cpp DEPENDS teelogging PTHREADS)

