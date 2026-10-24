#pragma force_active on
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;

extern s8 *fn_8022EFF8(int);
extern void fn_80242908(s8 *);

s32 fn_8024663C(s32 arg0, s32 arg1, s32 arg2, u32 arg3)
{
    s8 *p;

    p = fn_8022EFF8(2);
    if (p == 0) {
        return 0;
    }

    *(s16 *)(p + 2) = 10;
    *(s16 *)(p + 4) = 0;
    p[8] = 0x33;
    p[9] = 0xC;
    p[10] = 7;
    p[11] = arg0;
    p[12] = arg0 >> 8;
    p[13] = arg1;
    p[14] = arg2;
    p[15] = arg2 >> 8;
    p[16] = arg3;
    p[17] = (arg3 >> 8) & 0xFF;

    fn_80242908(p);
    return 1;
}
