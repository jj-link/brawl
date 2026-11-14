#include <types.h>
#pragma force_active on

extern u8 lbl_805A23C8;
extern u8 lbl_805A23C9;
extern u8 lbl_805A23CA;
extern u8 lbl_805A23CB;
extern u8 lbl_805A23CC;
extern u8 lbl_805A23CD;
extern u8 lbl_805A23CE;
extern u8 lbl_805A23CF;

extern "C" int fn_800E10B0(void* arg0, const u16* arg1, const void* arg2, const void* arg3, int arg4, int arg5, int arg6, void* arg7, int arg8);

extern "C" int fn_800E0F7C(void* arg0, const u16* arg1) {
    u16 buf[24];
    u8 c0[4];
    u8 c1[4];
    int w0;
    int w1;
    const u16* p;
    u16* q;
    int i;
    int k;

    c0[0] = lbl_805A23C8;
    c0[1] = lbl_805A23C9;
    c0[2] = lbl_805A23CA;
    c0[3] = lbl_805A23CB;
    c1[0] = lbl_805A23CC;
    c1[1] = lbl_805A23CD;
    c1[2] = lbl_805A23CE;
    c1[3] = lbl_805A23CF;

    i = 0;
    p = arg1;
    q = buf;
    while (i < 10 && *p != 0) {
        *q = *p;
        q++;
        i++;
        p++;
    }
    if (*p != 0) {
        buf[i] = 10;
        i++;
        q = &buf[i];
        k = 0;
        while (k < 10 && *p != 0) {
            *q = *p;
            q++;
            i++;
            k++;
            p++;
        }
    }
    buf[i] = 0;

    w1 = *(int*)c1;
    w0 = *(int*)c0;
    fn_800E10B0(arg0, buf, &w0, &w1, 0, 200, 48, 0, 20);
    return i;
}
