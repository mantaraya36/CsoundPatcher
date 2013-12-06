project(CsoundPatcher)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

include_directories(../../include)
#include_directories(../../iterfaces)
add_library(CsoundPatcher csengine.cpp signal.cpp sinosc.cpp out.cpp)
#target_link_libraries(CsoundPatcher csound csnd)

add_executable(PatcherTest main.cpp)
target_link_libraries(PatcherTest CsoundPatcher)
