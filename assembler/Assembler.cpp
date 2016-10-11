#include "Assembler.h"

Assembler::Assembler(std::string path) {
    this->source = Util::readFromFile(path.c_str());
    this->path = (char*)path.c_str();
    this->path[Util::bufLen(this->path) - 1] = 'c';
}

Assembler::~Assembler() {
    free(this->source);
}

void Assembler::run() {
    char* lex = (char*)malloc(256);
    int ptr = 0;
    int sourcePtr = 0;
    BufferHandler buf(5, 1);
    int size = 0;

    while (source[sourcePtr] != '\0') {
        lex[ptr++] = source[sourcePtr++];

        // ICONST
        if (Util::stringEquals(lex, "iconst")) {
            buf.add(ICONST);
            goto oneArg;
        }

        // IADD
        else if (Util::stringEquals(lex, "iadd")) {
            buf.add(IADD);
            goto reset;
        }

        // ISUB
        else if (Util::stringEquals(lex, "isub")) {
            buf.add(ISUB);
            goto reset;
        }

        // GSTORE
        else if (Util::stringEquals(lex, "gstore")) {
            buf.add(GSTORE);
            goto oneArg;
        }

        // GLOAD
        else if (Util::stringEquals(lex, "gload")) {
            buf.add(GLOAD);
            goto oneArg;
        }

        // PRINT
        else if (Util::stringEquals(lex, "print")) {
            buf.add(PRINT);
            goto reset;
        }

        // HALT
        else if (Util::stringEquals(lex, "halt")) {
            buf.add(HALT);
            goto reset;
        }

        // OTHERWISE
        else {
            // Skip the logic jumps
            continue;
        }

        //
        // LOGIC JUMPS
        //

        reset:
        {
            Util::resetCharBuffer(lex, 256);
            ptr = 0;
            sourcePtr++;
            size++;
            continue;
        }

        oneArg:
        {
            Util::resetCharBuffer(lex, 256);
            ptr = 0;
            while (source[sourcePtr] != '\n') {
                lex[ptr++] = source[sourcePtr++];
            }
            char c = (char) atoi(lex);
            buf.add(c);
            size++;
            goto reset;
        }
    }

    buf.set(0, (char)size);
    Util::writeToBinaryFile(path, buf.getData(), buf.getPointer());
}