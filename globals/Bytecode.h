#pragma once

#include <cstdlib>
#include <string>

enum Ops {
    NIL,
    ICONST,
    IADD,
    PRINT,
    HALT
};

class Bytecode {
private:
    int opcode;
    std::string name;
    int args;

public:
    static Bytecode* list;

    Bytecode(int opcode, std::string name, int args);
    ~Bytecode();

    static void init();

    int getOpcode();
    std::string getName();
    int getArgs();
};