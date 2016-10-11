#pragma once

#include <iostream>
#include <cstdlib>

#include "../globals/Bytecode.h"

#define DEFAULT_STACK_SIZE 512

class VM {
private:
    char* src;
    char* globals;
    char* stack;

    int sp = -1;
    int ip = 0;
    int fp = 0;

public:
    bool showTrace = false;

    VM(char* src, int start, int globals);
    virtual ~VM();

    void trace(int opcode);

    void run(int codeLength);
    void push(int data);
    int pop();
};