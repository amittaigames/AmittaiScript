#pragma once

#include <cstdlib>
#include <string>

enum Ops {
    NIL,
    ICONST,
    IADD,
    ISUB,
    GSTORE,
    GLOAD,
    PRINT,
    HALT
};

class Bytecode {
private:
    int opcode;
    std::string name;
    int args;

    static void add(Bytecode bc);
public:
    static Bytecode* list;

    Bytecode(int opcode, std::string name, int args);
    ~Bytecode();

    static void init();
    static void cleanUp();

    int getOpcode();
    std::string getName();
    int getArgs();
};