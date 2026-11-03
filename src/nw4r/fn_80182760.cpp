#include <string.h>
#pragma force_active on

extern char lbl_80465688[];
extern const float lbl_805A30B0;

extern "C" void* fn_80182760(char* self, const char* info) {
    float zero = lbl_805A30B0;
    void* a = self + 0x14;
    void* b = self + 0x20;
    for (int i = 0; i < 2; ++i) {
        ((int*)(self + 0x14))[i] = 0;
    }
    for (int i = 0; i < 2; ++i) {
        ((int*)(self + 0x20))[i] = 0;
    }
    *(int*)(self + 4) = 0;
    *(int*)(self + 8) = 0;
    *(char**)self = lbl_80465688;
    *(int*)(self + 0x10) = 0;
    *(void**)(self + 0x14) = a;
    *(void**)(self + 0x18) = a;
    *(int*)(self + 0x1c) = 0;
    *(void**)(self + 0x20) = b;
    *(void**)(self + 0x24) = b;
    *(float*)(self + 0x4c) = zero;
    *(float*)(self + 0x50) = zero;
    *(int*)(self + 0x0c) = 0;
    *(int*)(self + 0x28) = 0;
    self[0xd2] = 0;
    self[0xb6] = info[9];
    strncpy(self + 0xb8, info + 0xc, 16);
    self[0xc8] = 0;
    strncpy(self + 0xc9, info + 0x1c, 8);
    unsigned char value = info[0xa];
    self[0xd1] = 0;
    *(float*)(self + 0x2c) = *(const float*)(info + 0x24);
    *(float*)(self + 0x30) = *(const float*)(info + 0x28);
    *(float*)(self + 0x34) = *(const float*)(info + 0x2c);
    *(float*)(self + 0x38) = *(const float*)(info + 0x30);
    *(float*)(self + 0x3c) = *(const float*)(info + 0x34);
    *(float*)(self + 0x40) = *(const float*)(info + 0x38);
    *(float*)(self + 0x44) = *(const float*)(info + 0x3c);
    *(float*)(self + 0x48) = *(const float*)(info + 0x40);
    *(float*)(self + 0x4c) = *(const float*)(info + 0x44);
    *(float*)(self + 0x50) = *(const float*)(info + 0x48);
    self[0xb4] = value;
    self[0xb5] = value;
    self[0xb7] = info[8];
    return self;
}
