#include <iostream>

#include "globals/Bytecode.h"
#include "vm/VM.h"
#include "assembler/Assembler.h"

typedef enum _Mode {
    MODE_RUN_BYTECODE,
    MODE_RUN_LOADED,
    MODE_COMPILE_LOWLEVEL
} Mode;

int main(int argc, char* argv[]) {
    char code[] = {
        ICONST, 23,
        GSTORE, 0,
        ICONST, 1,
        ICONST, 2,
        IADD,
        PRINT,
        GLOAD, 0,
        PRINT,
        HALT
    };

    Mode testMode = MODE_RUN_LOADED;

    Bytecode::init();

    if (testMode == MODE_RUN_BYTECODE) {
        VM vm(code, 0, 256);
        vm.showTrace = true;        // For debug
        vm.run(sizeof(code));
    } else if (testMode == MODE_COMPILE_LOWLEVEL) {
        Assembler assembler("scripts/test.aa");
        assembler.run();
        std::cout << "Compilation finished" << std::endl;
    } else if (testMode == MODE_RUN_LOADED) {
        char* data = Util::readFromBinaryFile("scripts/test.ac");
        VM vm(data, 1, 256);
        vm.showTrace = true;
        vm.run(data[0]);
    }

    Bytecode::cleanUp();

    return 0;
}