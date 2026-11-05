#include <string.h>
#include <stdio.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_4D7A8[];
extern char lbl_27_data_4D7CC[];

void fn_27_2406A0(void* self)
{
    char* base = (char*)self;
    void* ptr = *(void**)(base + 0x40);

    *(int*)(base + 0x94) =
        (int)*(unsigned short*)((char*)ptr + 0x1A) + 0x31;
    *(int*)(base + 0x8C) = (int)*(unsigned short*)((char*)ptr + 0x1A);
    *(int*)(base + 0x90) = *(unsigned char*)((char*)ptr + 0x1C);

    unsigned int val =
        *(unsigned int*)((char*)*(void**)(base + 0xD0) + 0x620);
    *(int*)(base + 0xCC) = (int)val;

    int b3 = (val >> 24) & 0xFF;
    int b2 = (val >> 16) & 0xFF;
    int b1 = (val >> 8) & 0xFF;
    int b0 = val & 0xFF;

    memset(base + 0x48, 0, 0x40);

    if (b0 == 0) {
        sprintf(base + 0x48, lbl_27_data_4D7A8, b3, b2, b1, b3, b2, b1);
    } else {
        signed char suffix = (signed char)(b0 + 0x60);
        sprintf(base + 0x48, lbl_27_data_4D7CC, b3, b2, b1, suffix, b3, b2, b1, suffix);
    }
}
}
