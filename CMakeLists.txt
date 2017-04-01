project(teelogging CXX)
cmake_minimum_required(VERSION 3.2.2)

set(CMAKI_REPOSITORY "http://artifacts.myftp.biz:8080")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmaki/cmaki.cmake")
cmaki_setup()

cmaki_find_package(spdlog)
cmaki2_static_library(teelogging teelogging_manager.cpp PTHREADS)

cmaki2_gtest(teelogging tests/test1.cpp DEPENDS teelogging PTHREADS)

