#include "Bytecode.h"

Bytecode* Bytecode::list;

void Bytecode::init() {
    list = (Bytecode*)malloc(sizeof(Bytecode) * (HALT + 1));

    list[0] = Bytecode(NIL, "???", 0);
    list[1] = Bytecode(ICONST, "iconst", 1);
    list[2] = Bytecode(IADD, "iadd", 0);
    list[3] = Bytecode(PRINT, "print", 0);
    list[4] = Bytecode(HALT, "halt", 0);
}

Bytecode::Bytecode(int opcode, std::string name, int args) {
    this->opcode = opcode;
    this->name = name;
    this->args = args;
}

Bytecode::~Bytecode() {
    // Stub
}

int Bytecode::getOpcode() {
    return opcode;
}

std::string Bytecode::getName() {
    return name;
}

int Bytecode::getArgs() {
    return args;
}