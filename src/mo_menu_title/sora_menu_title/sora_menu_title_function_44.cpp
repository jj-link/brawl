#include <string.h>
#include <stdio.h>
#pragma force_active on

extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern char lbl_24_data_0[];
extern char lbl_24_data_198[];
}

struct Data0 {
    char first;
};

#pragma push
#pragma opt_propagation off
extern "C" void* fn_24_44(void* self) {
    char* p = (char*)self;
    Data0* base = (Data0*)lbl_24_data_0;
    char Data0::*first = &Data0::first;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, &(base->*first), 8, 0xF, 8, true);
    *(int*)(p + 0x40) = 0;
    *(char**)(p + 0x3C) = lbl_24_data_198;
    *(int*)(p + 0x1C4) = 0;
    *(int*)(p + 0x1C8) = 0;
    *(int*)(p + 0x1CC) = 0;
    *(int*)(p + 0x1D4) = 0;
    memset(p + 0x44, 0, 0x80);
    sprintf(p + 0x44, (char*)base + 8);
    sprintf(p + 0x64, (char*)base + 0x24);
    sprintf(p + 0x84, (char*)base + 0x40);
    sprintf(p + 0xA4, (char*)base + 0x5C);
    memset(p + 0xC4, 0, 0x80);
    sprintf(p + 0xC4, (char*)base + 0x78);
    sprintf(p + 0xE4, (char*)base + 0x8C);
    sprintf(p + 0x104, (char*)base + 0xA0);
    sprintf(p + 0x124, (char*)base + 0xB4);
    memset(p + 0x144, 0, 0x80);
    sprintf(p + 0x144, (char*)base + 0xC8);
    sprintf(p + 0x164, (char*)base + 0xE0);
    sprintf(p + 0x184, (char*)base + 0xF8);
    sprintf(p + 0x1A4, (char*)base + 0x110);
    return self;
}
#pragma pop