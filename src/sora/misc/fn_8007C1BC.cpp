#include <types.h>
#pragma force_active on

extern "C" unsigned int __cvt_fp2unsigned(float);
extern char g_thpObject[];
extern float lbl_805A1B40;
extern float lbl_805A1B44;

extern "C" int fn_8007C1BC() {
    int r;
    if (*(int*)(g_thpObject + 0xA0) != 0) {
        if (*(int*)(g_thpObject + 0xB0) != 0) {
            r = (*(int*)(g_thpObject + 0x58) + 0x1F) & ~0x1F;
        } else {
            r = ((*(int*)(g_thpObject + 0x44) + 0x1F) & ~0x1F) * 6;
        }
        unsigned int n = *(unsigned int*)(g_thpObject + 0x80) * *(unsigned int*)(g_thpObject + 0x84);
        unsigned int a = (n + 0x1F) & ~0x1F;
        unsigned int b = ((n >> 2) + 0x1F) & ~0x1F;
        r += a * 3;
        int c = b * 3;
        r += c;
        r += c;
        if (*(unsigned char*)(g_thpObject + 0xA7) != 0) {
            r += (((*(int*)(g_thpObject + 0x48) * 4) + 0x1F) & ~0x1F) * 6;
            r += *(int*)(g_thpObject + 0x8C) * ((((__cvt_fp2unsigned(lbl_805A1B40 + (float)(*(unsigned int*)(g_thpObject + 0x90) * 0x28) / lbl_805A1B44)) + 0x1F) * 2) & ~0x3F);
        }
        return r + 0x1000;
    }
    return 0;
}
