#include <iostream>
#include "globals/Bytecode.h"
#include "vm/VM.h"

int main(int argc, char* argv[]) {
    int code[] = {
        ICONST, 1,
        ICONST, 2,
        IADD,
        ICONST, 57,
        IADD,
        PRINT,
        HALT
    };

    Bytecode::init();

    VM vm(code, 0, 0);
    vm.showTrace = true;        // For debug
    vm.run();

    return 0;
}