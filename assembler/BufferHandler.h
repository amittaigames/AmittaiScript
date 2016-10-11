#pragma once

#include <cstdlib>

class BufferHandler {
private:
    char* data = nullptr;
    int ptr = 0;
    int size = 0;
public:
    BufferHandler(int size);
    BufferHandler(int size, int offset);
    virtual ~BufferHandler();

    void add(char c);
    void set(int index, char c);
    void moreSpace();

    char* getData();
    int getPointer();
};