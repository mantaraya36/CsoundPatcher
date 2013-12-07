project(CsoundPatcher)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

# Csound
set(CSOUND_LIB_DIR /usr/local/lib)
FIND_LIBRARY(CSOUND_LIB csound64 CSOUND_LIB_DIR)
FIND_LIBRARY(CSND6_LIB csnd6 CSOUND_LIB_DIR)
include_directories(/usr/local/include/csound)
set(CSOUND_LIBS ${CSOUND_LIB} ${CSND6_LIB})
add_definitions(-DUSE_DOUBLE)


add_library(CsoundPatcher csengine.cpp signal.cpp sinosc.cpp out.cpp)
target_link_libraries(CsoundPatcher ${CSOUND_LIBS})

add_executable(PatcherTest main.cpp)
target_link_libraries(PatcherTest CsoundPatcher ${CSOUND_LIBS})

