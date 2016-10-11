#pragma once

#include <string>

#include "../globals/Util.h"
#include "../globals/Bytecode.h"
#include "BufferHandler.h"

class Assembler {
private:
    char* source;
    char* path;

public:
    Assembler(std::string path);
    virtual ~Assembler();

    void run();
};