#include <types.h>
#include <string.h>
#pragma force_active on

extern "C" {
extern char lbl_2_data_EF0[];
extern char lbl_2_data_12B8[];

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_800B96E8(void*, int);
void fn_2_6470(void*);
void fn_2_647C(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

inline void clearWords(int* p, int* e) {
    do {
        *p = 0;
        p++;
    } while (p < e);
}

extern "C" char* fn_2_86B8(char* self) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_2_data_EF0, 8, 0xF, 8, true);
    *(int*)(self + 0x9C) = 0;
    *(char**)(self + 0x3C) = lbl_2_data_12B8;
    *(int*)(self + 0xA0) = 0;
    *(int*)(self + 0xA4) = 0;
    *(int*)(self + 0xA8) = 0;
    *(int*)(self + 0xAC) = 0;
    *(int*)(self + 0xB0) = 0;
    clearWords((int*)(self + 0xB4), (int*)(self + 0xC4));
    clearWords((int*)(self + 0xC4), (int*)(self + 0xD4));
    *(int*)(self + 0xE4) = 0;
    fn_800B96E8(self + 0x190, 0xFF);
    *(u8*)(self + 0x258) = 0;
    *(u8*)(self + 0x259) = 1;
    *(int*)(self + 0x25C) = 0;
    __construct_array(self + 0x264, fn_2_6470, fn_2_647C, 4, 0xC);
    *(int*)(self + 0x298) = 0;
    *(int*)(self + 0x29C) = 0;
    *(int*)(self + 0x2B8) = 0;
    *(int*)(self + 0x2BC) = 0;
    *(u8*)(self + 0x2E8) = 0;
    *(int*)(self + 0x2FC) = -1;
    *(u8*)(self + 0x2C) &= ~2;
    memset(self + 0x2A0, 0, 0x10);
    memset(self + 0x2B0, 0, 8);
    memset(self + 0x2C0, 0, 0x28);
    return self;
}
