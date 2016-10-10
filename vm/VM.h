#pragma once

#include <iostream>
#include <cstdlib>

#include "../globals/Bytecode.h"

#define DEFAULT_STACK_SIZE 512

class VM {
private:
    int* src;
    int* globals;
    int* stack;

    int sp = -1;
    int ip = 0;
    int fp = 0;

public:
    bool showTrace = false;

    VM(int* src, int start, int globals);
    virtual ~VM();

    void trace(int opcode);

    void run();
    void push(int data);
    int pop();
};