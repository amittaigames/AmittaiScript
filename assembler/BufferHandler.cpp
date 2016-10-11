#include "BufferHandler.h"

BufferHandler::BufferHandler(int size) {
    this->size = size;
    this->ptr = 0;
    this->data = (char*)malloc(sizeof(char) * size);
}

BufferHandler::BufferHandler(int size, int offset) {
    this->size = size;
    this->ptr = offset;
    this->data = (char*)malloc(sizeof(char) * size);
}

BufferHandler::~BufferHandler() {
    //free(this->data);
}

void BufferHandler::add(char c) {
    if (ptr == size)
        moreSpace();
    data[ptr++] = c;
}

void BufferHandler::set(int index, char c) {
    data[index] = c;
}

void BufferHandler::moreSpace() {
    data = (char*)realloc(data, sizeof(char) * size * 2);
    size *= 2;
}

char *BufferHandler::getData() {
    return data;
}

int BufferHandler::getPointer() {
    return ptr;
}
