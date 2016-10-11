#include "Util.h"

int Util::bufLen(char *buf) {
    int length = 0;
    while (buf[length] != '\0')
        length++;
    return length;
}

char* Util::readFromFile(const char* path) {
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("Error creating file object! (R)\n");
        return nullptr;
    }

    fseek(file, 0, SEEK_END);
    int size = (int)ftell(file);
    fseek(file, 0, SEEK_SET);

    char* data = (char*)malloc(sizeof(char) * size);
    fread(data, 1, size, file);
    data[size] = '\0';

    fclose(file);
    return data;
}

char *Util::readFromBinaryFile(const char *path) {
    FILE* file = fopen(path, "rb");
    if (file == NULL) {
        printf("Error creating file object! (R)\n");
        return nullptr;
    }

    fseek(file, 0, SEEK_END);
    int size = (int)ftell(file);
    fseek(file, 0, SEEK_SET);

    char* data = (char*)malloc(sizeof(char) * size);
    fread(data, 1, size, file);
    data[size] = '\0';

    fclose(file);
    return data;
}

void Util::writeToBinaryFile(const char *path, char *data, int elements) {
    FILE* file = fopen(path, "wb");
    if (file == NULL) {
        printf("Error creating file object! (W)\n");
        return;
    }

    fwrite(data, 1, elements, file);
    fclose(file);
}

void Util::resetCharBuffer(char *buf, int len) {
    for (int i = 0; i < len; i++) {
        buf[i] = '\0';
    }
}

bool Util::stringEquals(char *a, char *b) {
    int aLen = bufLen(a);
    int bLen = bufLen(b);
    if (aLen != bLen)
        return false;

    bool result = true;
    for (int i = 0; i < aLen; i++) {
        if (a[i] != b[i]) {
            result = false;
            break;
        }
    }

    return result;
}
