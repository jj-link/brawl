#pragma force_active on
#include <revolution/DVD/dvd.h>

extern "C" {
extern char* lbl_805A01F8;
extern int lbl_805A01E8;
extern int lbl_805A01EC;
extern unsigned int lbl_805A01F0;
extern int lbl_805A01F4;
extern char lbl_8059DB98;
extern char g_thpObject[];
void* memcpy(void*, const void*, unsigned long);
int strcmp(const char*, const char*);
int fn_801F6708(void*, void*, unsigned int, unsigned int,
                void (*)(void*, void*), void*);
int fn_801F6524(void*);

int fn_8007BE4C(void) {
    switch (lbl_805A01E8) {
    case 0:
        fn_801F6708(g_thpObject, lbl_805A01F8 + 0x20, 0x40, 0, 0, (void*)2);
        lbl_805A01E8 = lbl_805A01E8 + 1;
        break;
    case 1:
        if (DVDGetCommandBlockStatus((DVDCommandBlock*)g_thpObject) == 0) {
            lbl_805A01E8 = lbl_805A01E8 + 1;
        }
        break;
    case 2:
        memcpy(g_thpObject + 0x3C, lbl_805A01F8 + 0x20, 0x30);
        if (strcmp(g_thpObject + 0x3C, &lbl_8059DB98) != 0) {
            fn_801F6524(g_thpObject);
            return -1;
        }
        if ((*(unsigned int*)(g_thpObject + 0x40) - 0x10000) != 0x1000) {
            fn_801F6524(g_thpObject);
            return -1;
        }
        lbl_805A01EC = *(int*)(g_thpObject + 0x5C);
        fn_801F6708(g_thpObject, lbl_805A01F8 + 0x20, 0x20, lbl_805A01EC, 0,
                    (void*)2);
        lbl_805A01E8 = lbl_805A01E8 + 1;
        break;
    case 3:
        if (DVDGetCommandBlockStatus((DVDCommandBlock*)g_thpObject) == 0) {
            lbl_805A01E8 = lbl_805A01E8 + 1;
        }
        break;
    case 4:
        memcpy(g_thpObject + 0x6C, lbl_805A01F8 + 0x20, 0x14);
        lbl_805A01EC = lbl_805A01EC + 0x14;
        *(unsigned char*)(g_thpObject + 0xA7) = 0;
        lbl_805A01F0 = 0;
        lbl_805A01E8 = lbl_805A01E8 + 1;
        break;
    case 5:
        if (lbl_805A01F0 < *(unsigned int*)(g_thpObject + 0x6C)) {
            unsigned char b = *(unsigned char*)(g_thpObject + 0x70 + lbl_805A01F0);
            switch (b) {
            case 0:
                fn_801F6708(g_thpObject, lbl_805A01F8 + 0x20, 0x20,
                            lbl_805A01EC, 0, (void*)2);
                break;
            case 1:
                fn_801F6708(g_thpObject, lbl_805A01F8 + 0x20, 0x20,
                            lbl_805A01EC, 0, (void*)2);
                break;
            default:
                fn_801F6524(g_thpObject);
                return -1;
            }
            lbl_805A01E8 = lbl_805A01E8 + 1;
        } else {
            lbl_805A01E8 = lbl_805A01E8 + 2;
        }
        break;
    case 6:
        if (DVDGetCommandBlockStatus((DVDCommandBlock*)g_thpObject) == 0) {
            unsigned char b = *(unsigned char*)(g_thpObject + 0x70 + lbl_805A01F0);
            switch (b) {
            case 0:
                memcpy(g_thpObject + 0x80, lbl_805A01F8 + 0x20, 0xC);
                lbl_805A01EC = lbl_805A01EC + 0xC;
                break;
            case 1:
                memcpy(g_thpObject + 0x8C, lbl_805A01F8 + 0x20, 0x10);
                *(unsigned char*)(g_thpObject + 0xA7) = 1;
                lbl_805A01EC = lbl_805A01EC + 0x10;
                break;
            }
            lbl_805A01F0 = lbl_805A01F0 + 1;
            lbl_805A01E8 = lbl_805A01E8 - 1;
        }
        break;
    case 7:
        *(unsigned char*)(g_thpObject + 0xA5) = 0;
        *(unsigned char*)(g_thpObject + 0xA4) = 0;
        *(unsigned char*)(g_thpObject + 0xA6) = 0;
        *(int*)(g_thpObject + 0xB0) = lbl_805A01F4;
        *(int*)(g_thpObject + 0xA0) = 1;
        return 1;
    }
    return 0;
}
}
