#include "VM.h"

VM::VM(int* src, int start, int globals) {
    this->src = src;
    this->ip = start;
    this->globals = (int*)malloc(sizeof(int) * globals);
    this->stack = (int*)malloc(sizeof(int) * DEFAULT_STACK_SIZE);
}

VM::~VM() {
    free(this->globals);
    free(this->stack);
}

void VM::trace(int opcode) {
    Bytecode inst = Bytecode::list[opcode];
    printf("%04d: %s", ip, inst.getName().c_str());
    for (int i = 0; i < inst.getArgs(); i++) {
        printf(", %d ", src[ip + (i + 1)]);
    }
    printf("\n");
}

void VM::run() {
    while (ip <= sizeof(src)) {
        int opcode = src[ip];
        if (showTrace) trace(opcode);
        ip++;
        switch (opcode) {
            case ICONST: {
                push(src[ip++]);
                break;
            }
            case IADD: {
                push(pop() + pop());
                break;
            }
            case PRINT: {
                std::cout << pop() << std::endl;
                break;
            }
            case HALT: {
                goto endOfLoop;
            }
            default: {
                std::cerr << "Invalid opcode: " << opcode << std::endl;
                goto endOfLoop;
            }
        }
    }
    endOfLoop:
        return;
}

void VM::push(int data) {
    stack[++sp] = data;
}

int VM::pop() {
    return stack[sp--];
}