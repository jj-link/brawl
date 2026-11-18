#include <types.h>
#include <string.h>
#pragma force_active on

extern "C" {
extern char lbl_13_data_3C[];
extern char lbl_13_data_1C0[];

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_13_444(void*);
void fn_13_450(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

inline void clearWords(int* p, int* e) {
    do {
        *p = 0;
        p++;
    } while (p < e);
}

extern "C" char* fn_13_DC(char* self) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_13_data_3C, 8, 0xF, 8, true);
    *(int*)(self + 0x40) = 0;
    *(char**)(self + 0x3c) = lbl_13_data_1C0;
    *(int*)(self + 0x44) = 0;
    *(int*)(self + 0x48) = 0;
    clearWords((int*)(self + 0x48), (int*)(self + 0x54));
    *(int*)(self + 0x54) = 0;
    clearWords((int*)(self + 0x54), (int*)(self + 0x5c));
    *(int*)(self + 0x5c) = 0;
    *(int*)(self + 0xe4) = 0;
    __construct_array(self + 0xe8, fn_13_444, fn_13_450, 4, 8);
    *(u8*)(self + 0x108) = 0;
    *(int*)(self + 0x18c) = 0;
    *(int*)(self + 0x190) = 0;
    *(int*)(self + 0x194) = 0;
    *(u8*)(self + 0x2c) &= ~2;
    *(int*)(self + 0x40) = 0;
    *(int*)(self + 0x44) = 0;
    *(int*)(self + 0x48) = 0;
    *(int*)(self + 0x4c) = 0;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0x54) = 0;
    *(int*)(self + 0x58) = 0;
    *(int*)(self + 0x5c) = 0;
    *(int*)(self + 0x60) = 0;
    *(int*)(self + 0x64) = 0;
    *(int*)(self + 0x68) = 0;
    *(int*)(self + 0x6c) = 0;
    *(int*)(self + 0x70) = 0;
    *(int*)(self + 0x74) = 0;
    *(int*)(self + 0x78) = 0;
    *(int*)(self + 0x7c) = 0;
    *(int*)(self + 0x80) = 0;
    *(int*)(self + 0x84) = 0;
    *(int*)(self + 0x88) = 0;
    *(int*)(self + 0x8c) = 0;
    *(int*)(self + 0x90) = 0;
    *(int*)(self + 0x94) = 0;
    *(int*)(self + 0x98) = 0;
    *(int*)(self + 0x9c) = 0;
    *(int*)(self + 0xa0) = 0;
    *(int*)(self + 0xa4) = 0;
    *(int*)(self + 0xa8) = 0;
    memset(self + 0xac, 0, 0x38);
    memset(self + 0x10c, 0, 0x80);
    return self;
}
