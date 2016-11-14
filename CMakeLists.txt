CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

set(CMAKI_REPOSITORY "http://artifacts.myftp.biz:8080")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmaki/cmaki.cmake")
cmaki_setup()

cmaki_find_package(cppformat)
cmaki_find_package(spdlog)
cmaki2_library(Logger LoggerManager.cpp)
cmaki2_gtest(Logger tests/test1.cpp DEPENDS Logger)

