#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;
extern void *fn_8022EFF8(int);
extern void fn_80242908(void *);
s32 fn_802448BC(const u8 *arg0, s8 arg1, s8 arg2) {
    u8 *p = (u8 *)fn_8022EFF8(2);
    if (p == 0) return 0;
    *(u16 *)(p + 2) = 8;
    *(u16 *)(p + 4) = 0;
    p[8] = 1;
    p[9] = 4;
    p[10] = 5;
    p[11] = arg0[2];
    p[12] = arg0[1];
    p[13] = arg0[0];
    p[14] = (u8)arg1;
    p[15] = (u8)arg2;
    fn_80242908(p);
    return 1;
}