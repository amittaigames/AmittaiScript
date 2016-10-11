#include "VM.h"

VM::VM(char* src, int start, int globals) {
    this->src = src;
    this->ip = start;
    this->globals = (char*)malloc(sizeof(char) * globals);
    this->stack = (char*)malloc(sizeof(char) * DEFAULT_STACK_SIZE);
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

void VM::run(int codeLength) {
    while (ip <= codeLength) {
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
            case ISUB: {
                push(pop() - pop());
                break;
            }
            case GSTORE: {
                globals[src[ip++]] = pop();
                break;
            }
            case GLOAD: {
                push(globals[src[ip++]]);
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