#pragma once

#include <stdio.h>
#include <cstdlib>

class Util {
public:
    static int bufLen(char* buf);
    static char* readFromFile(const char* path);
    static void writeToBinaryFile(const char *path, char *data, int elements);
    static char* readFromBinaryFile(const char* path);
    static void resetCharBuffer(char* buf, int len);
    static bool stringEquals(char* a, char* b);
};