#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8* fn_8022EFF8(int);
extern void fn_80242908(void*);

int fn_8024567C(int a, u32 b, u32 c, int d, int e, int f, u32 g)
{
    u8* p = fn_8022EFF8(2);

    if (!p)
        return 0;

    *(u16*)(p + 2) = 20;
    *(u16*)(p + 4) = 0;
    p[8] = 40;
    p[9] = 4;
    p[10] = 17;
    p[11] = a;
    p[12] = a >> 8;
    p[13] = b;
    p[14] = b >> 8;
    p[15] = b >> 16;
    p[16] = b >> 24;
    p[17] = c;
    p[18] = c >> 8;
    p[19] = c >> 16;
    p[20] = c >> 24;
    p[21] = d;
    p[22] = d >> 8;
    p[23] = e;
    p[24] = e >> 8;
    p[25] = f;
    p[26] = g;
    p[27] = g >> 8;

    fn_80242908(p);
    return 1;
}
