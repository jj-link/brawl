#pragma force_active on
#include <string.h>

extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    void*, const char*, int, int, int, bool);
void fn_800B96E8(void*, int);
void __construct_array(
    void*, void (*)(void*), void (*)(void*), unsigned long, int);
void* memset(void*, int, unsigned long);

extern const char lbl_80456DD8[];
extern char lbl_80456F5C[];
extern void fn_800C02C8(void*);
extern void fn_800C02D8(void*);

void* fn_800C0164(void* self) {
    char* b = (char*)self;

    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        self, lbl_80456DD8, 8, 0xF, 8, true);

    *(int*)(b + 0x58) = 0;
    *(void**)(b + 0x3C) = lbl_80456F5C;
    *(int*)(b + 0x5C) = 0;
    fn_800B96E8(b + 0x60, 0xFF);

    *(char*)(b + 0x108) = 1;
    *(int*)(b + 0x10C) = 5;
    *(int*)(b + 0x110) = 6;
    *(int*)(b + 0x114) = 0;
    *(int*)(b + 0x118) = 0;
    *(int*)(b + 0x21C) = 0;
    *(int*)(b + 0x220) = 0;
    *(int*)(b + 0x224) = 0;
    *(int*)(b + 0x228) = 0;
    *(int*)(b + 0x22C) = 0;
    *(int*)(b + 0x230) = 0;

    __construct_array(b + 0x234, fn_800C02C8, fn_800C02D8, 8, 0x10);

    *(char*)(b + 0x2B4) = 0;
    *(int*)(b + 0x2B8) = 0;
    *(int*)(b + 0x2BC) = 0;
    *(int*)(b + 0x2C0) = 0;

    __construct_array(b + 0x2C4, fn_800C02C8, fn_800C02D8, 8, 0x10);

    *(int*)(b + 0x344) = 0;
    *(int*)(b + 0x348) = 0;

    __construct_array(b + 0x34C, fn_800C02C8, fn_800C02D8, 8, 0x10);

    *(int*)(b + 0x3CC) = -1;
    *(char*)(b + 0x3D0) = 0;

    unsigned int t = *(unsigned char*)(b + 0x2C);
    *(unsigned char*)(b + 0x2C) = (unsigned char)(t & 0xFFFFFFFDu);

    *(int*)(b + 0x40) = 0;
    *(int*)(b + 0x44) = 0;
    *(int*)(b + 0x48) = 0;
    *(int*)(b + 0x4C) = 0;
    *(int*)(b + 0x50) = 0;
    *(int*)(b + 0x54) = 0;

    memset(b + 0x11C, 0, 0x100);
    return self;
}
}
