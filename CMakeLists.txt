CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

set(CMAKI_REPOSITORY "http://artifacts.myftp.biz:8080")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmaki/cmaki.cmake")
cmaki_setup()

cmaki_find_package(spdlog)
cmaki2_library(teelogging teelogging_manager.cpp)
cmaki2_gtest(teelogging tests/test1.cpp DEPENDS teelogging PTHREADS)

