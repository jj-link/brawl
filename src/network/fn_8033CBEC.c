#include <string.h>
#pragma force_active on
extern int lbl_805A0FA8;
extern int lbl_805338B0[];
extern char lbl_8048AB1C[], lbl_8048AB0C[];
extern void fn_80335638(int, const char *, ...);
extern void fn_80335450(int, int, int);
extern void fn_803425D8(int);

void fn_8033CBEC(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7)
{
    int i;
    int *p;
    int *q;
    lbl_805A0FA8 = arg0;
    *(int *)(arg0 + 0) = arg1;
    *(int *)(lbl_805A0FA8 + 4) = arg2;
    *(int *)(lbl_805A0FA8 + 8) = arg3;
    *(int *)(lbl_805A0FA8 + 0x10) = 0;
    *(int *)(lbl_805A0FA8 + 0x30) = 0;
    *(short *)(lbl_805A0FA8 + 0x2e) = 0;
    *(int *)(lbl_805A0FA8 + 0xf8) = 0;
    *(int *)(lbl_805A0FA8 + 0x1b4) = 0;
    *(char *)(lbl_805A0FA8 + 0x1b) = 0;
    *(int *)(lbl_805A0FA8 + 0x1f0) = 0;
    *(int *)(lbl_805A0FA8 + 0x218) = 0;
    *(int *)(lbl_805A0FA8 + 0x30c) = arg4;
    *(int *)(lbl_805A0FA8 + 0x310) = arg5;
    *(int *)(lbl_805A0FA8 + 0x314) = arg6;
    *(int *)(lbl_805A0FA8 + 0x318) = arg7;
    memset((void *)(lbl_805A0FA8 + 0x31c), 0, 0x40);
    *(int *)(lbl_805A0FA8 + 0x35c) = 0;
    *(int *)(lbl_805A0FA8 + 0x480) = 0;
    *(int *)(lbl_805A0FA8 + 0x484) = 0;
    *(int *)(lbl_805A0FA8 + 0x490) = 0;
    *(int *)(lbl_805A0FA8 + 0x494) = 0;
    q = (int *)lbl_805A0FA8;
    q[0x4bc / 4] = 0;
    q[0x4b8 / 4] = 0;
    q[0x4c4 / 4] = 0;
    q[0x4c0 / 4] = 0;
    q[0x498 / 4] = 0;
    *(int *)(lbl_805A0FA8 + 0x49c) = 0;
    *(int *)(lbl_805A0FA8 + 0x4a0) = 0;
    *(char *)(lbl_805A0FA8 + 0x4a4) = 0;
    *(char *)(lbl_805A0FA8 + 0x4a5) = 0;
    *(char *)(lbl_805A0FA8 + 0x16) = 0;
    *(char *)(lbl_805A0FA8 + 0x17) = 0;
    q = (int *)lbl_805A0FA8;
    q[0x18c / 4] = 0;
    q[0x188 / 4] = 0;
    fn_80335638(4, lbl_8048AB1C, lbl_8048AB0C);
    i = 0;
    p = lbl_805338B0;
    do {
        if (p[1]) fn_80335450(4, p[1], 0);
        i++;
        p += 3;
    } while (i < 0x9a);
    memset(lbl_805338B0, 0, 0x738);
    fn_803425D8(0);
}