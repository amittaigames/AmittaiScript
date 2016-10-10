#include "Bytecode.h"

Bytecode* Bytecode::list;

void Bytecode::init() {
    list = (Bytecode*)malloc(sizeof(Bytecode) * (HALT + 1));

    add(Bytecode(NIL, "???", 0));
    add(Bytecode(ICONST, "iconst", 1));
    add(Bytecode(IADD, "iadd", 0));
    add(Bytecode(ISUB, "isub", 0));
    add(Bytecode(ISTORE, "istore", 1));
    add(Bytecode(ILOAD, "iload", 1));
    add(Bytecode(PRINT, "print", 0));
    add(Bytecode(HALT, "halt", 0));
}

void Bytecode::add(Bytecode bc) {
    list[bc.getOpcode()] = bc;
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