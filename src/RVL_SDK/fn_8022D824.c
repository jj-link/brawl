#include <revolution/OS/OSInterrupt.h>
#include <string.h>
#pragma force_active on
extern unsigned char lbl_8047E8D0[];
extern unsigned char lbl_8047F810[];
extern unsigned char lbl_804FB4A0[];
extern unsigned char lbl_804FBC50[];
extern unsigned char lbl_805A0CF9;
extern unsigned char lbl_805A0CFA;
extern void fn_8022E928(void *, ...);
extern void fn_8023B45C(unsigned short, int, void *, int);
extern void fn_8023B694(unsigned short);
void fn_8022D824(int arg0, unsigned char *arg1) {
    unsigned char *base = lbl_8047E8D0;
    unsigned char t;
    unsigned char *g;
    unsigned char status;
    int saved, temp;
    unsigned short v;
    switch (arg0) {
    case 0:
        fn_8022E928(base + 0xAA4, arg1[0], arg1[1], arg1[2], arg1[3],
                    arg1[4], arg1[5], arg1[6], arg1[7], arg1[8],
                    (signed char)arg1[9]);
        g = lbl_804FB4A0;
        status = g[0x6E7];
        lbl_805A0CF9 = arg1[9];
        if (status == 1 ||
            (status == 0 &&
             (saved = OSDisableInterrupts(), t = lbl_804FB4A0[0x6E5],
              OSRestoreInterrupts(saved), t < 3))) {
            v = 0x1900;
        } else {
            v = 0x10000 - 0x8000;
        }
        fn_8023B694(v);
        return;
    case 1:
        fn_8022E928(base + 0xAE8);
        return;
    case 2:
        memcpy(lbl_804FBC50, arg1, 6);
        memcpy(lbl_804FBC50 + 6, arg1 + 6, 0x40);
        temp = *(int *)(arg1 + 0x100);
        *(int *)(lbl_804FBC50 + 0x100) = temp;
        lbl_805A0CFA++;
        fn_8022E928(base + 0xAFC, lbl_804FBC50[0], lbl_804FBC50[1],
                    lbl_804FBC50[2], lbl_804FBC50[3], lbl_804FBC50[4],
                    lbl_804FBC50[5], (int)(lbl_804FBC50 + 6), temp);
        return;
    case 3:
        fn_8022E928(base + 0xB3C);
        lbl_804FB4A0[0xC] = 4;
        return;
    case 4:
        fn_8022E928(base + 0xB50);
        fn_8023B45C(0xFC4C, 0x1C, lbl_8047F810, 0);
        lbl_805A0CFA = 0;
        memset(lbl_804FBC50, 0, 0x108);
        lbl_804FB4A0[0xC] = 4;
        return;
    default:
        fn_8022E928(base + 0xB60);
        return;
    }
}