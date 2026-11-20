#include <types.h>
#pragma force_active on

extern "C" char g_thpObject[];
extern "C" int* lbl_805A01F8;
extern "C" float lbl_805A1B40;
extern "C" float lbl_805A1B44;
extern "C" void fn_801D76BC(void* addr, unsigned int size);

extern "C" int fn_8007C2E4(char* arg0) {
    int audio;
    int scaled;
    char* p;
    char* q;
    unsigned int j;
    unsigned int size;
    unsigned int size2;
    unsigned int tmp;
    unsigned int mul;

    if (*(int*)(g_thpObject + 0xA0) != 0 && *(unsigned char*)(g_thpObject + 0xA4) == 0) {
        if (*(int*)(g_thpObject + 0xB0) != 0) {
            *(char**)(g_thpObject + 0xB4) = arg0;
            p = arg0 + *(unsigned int*)(g_thpObject + 0x58);
        } else {
            *(char**)(g_thpObject + 0xF0) = arg0;
            tmp = (*(unsigned int*)(g_thpObject + 0x44) + 0x1F) & ~0x1F;
            p = arg0 + tmp;
            *(char**)(g_thpObject + 0xFC) = p;
            p += tmp;
            *(char**)(g_thpObject + 0x108) = p;
            p += tmp;
            *(char**)(g_thpObject + 0x114) = p;
            p += tmp;
            *(char**)(g_thpObject + 0x120) = p;
            p += tmp;
            *(char**)(g_thpObject + 0x12C) = p;
            p += tmp;
        }
        mul = *(unsigned int*)(g_thpObject + 0x80) * *(unsigned int*)(g_thpObject + 0x84);
        size = (mul + 0x1F) & ~0x1F;
        size2 = ((mul >> 2) + 0x1F) & ~0x1F;
        q = (char*)&g_thpObject;
        for (j = 0; j < 3; j++) {
            *(char**)(q + 0x138) = p;
            fn_801D76BC(p, size);
            p += size;
            *(char**)(q + 0x13C) = p;
            fn_801D76BC(p, size2);
            p += size2;
            *(char**)(q + 0x140) = p;
            fn_801D76BC(p, size2);
            p += size2;
            q += 0x10;
        }
        if (*(unsigned char*)(g_thpObject + 0xA7) != 0) {
            *(int*)(g_thpObject + 0x170) = 0;
            scaled = *(int*)(g_thpObject + 0x48) * 4;
            audio = (scaled + 0x1F) & ~0x1F;
            *(char**)(g_thpObject + 0x168) = p;
            *(char**)(g_thpObject + 0x16C) = p;
            p += audio;
            *(char**)(g_thpObject + 0x174) = p;
            *(char**)(g_thpObject + 0x178) = p;
            p += audio;
            *(char**)(g_thpObject + 0x180) = p;
            *(char**)(g_thpObject + 0x184) = p;
            p += audio;
            *(char**)(g_thpObject + 0x18C) = p;
            *(char**)(g_thpObject + 0x190) = p;
            p += audio;
            *(char**)(g_thpObject + 0x198) = p;
            *(char**)(g_thpObject + 0x19C) = p;
            p += audio;
            *(int*)(g_thpObject + 0x17C) = 0;
            *(int*)(g_thpObject + 0x188) = 0;
            *(int*)(g_thpObject + 0x194) = 0;
            *(int*)(g_thpObject + 0x1A0) = 0;
            *(char**)(g_thpObject + 0x1A4) = p;
            *(char**)(g_thpObject + 0x1A8) = p;
            p += audio;
            *(int*)(g_thpObject + 0x1AC) = 0;
            *(char**)((char*)lbl_805A01F8 + 0x800) = p;
            p += (((unsigned int)(0.5f + ((float)(*(unsigned int*)(g_thpObject + 0x90) * 0x28) / 1000.0f)) + 0x1F) * 2) & ~0x3F;
            if (*(unsigned int*)(g_thpObject + 0x8C) == 2) {
                *(char**)((char*)lbl_805A01F8 + 0x804) = p;
                p += (((unsigned int)(0.5f + ((float)(*(unsigned int*)(g_thpObject + 0x90) * 0x28) / 1000.0f)) + 0x1F) * 2) & ~0x3F;
            }
        }
        *(char**)(g_thpObject + 0x9C) = p;
        return 1;
    }
    return 0;
}
