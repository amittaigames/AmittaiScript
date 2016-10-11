cmake_minimum_required(VERSION 3.6)
project(AmittaiScript)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp vm/VM.cpp vm/VM.h globals/Bytecode.cpp globals/Bytecode.h assembler/Assembler.cpp assembler/Assembler.h globals/Util.cpp globals/Util.h assembler/BufferHandler.cpp assembler/BufferHandler.h)
add_executable(AmittaiScript ${SOURCE_FILES})