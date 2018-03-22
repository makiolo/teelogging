project(teelogging CXX)
cmake_minimum_required(VERSION 3.0)
include("$ENV{CMAKI_PWD}/node_modules/npm-mas-mas/cmaki/cmaki.cmake")
cmaki_find_package(spdlog)
cmaki_library(teelogging teelogging_manager.cpp PTHREADS)
# cmaki_google_test(teelogging tests/test1.cpp DEPENDS teelogging PTHREADS)

