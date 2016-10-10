#include <iostream>
#include "globals/Bytecode.h"
#include "vm/VM.h"

int main(int argc, char* argv[]) {
    int code[] = {
        ICONST, 23,
        ISTORE, 0,
        ICONST, 1,
        ICONST, 2,
        IADD,
        PRINT,
        ILOAD, 0,
        PRINT,
        HALT
    };

    Bytecode::init();

    VM vm(code, 0, 5);
    vm.showTrace = true;        // For debug
    vm.run(sizeof(code));

    return 0;
}