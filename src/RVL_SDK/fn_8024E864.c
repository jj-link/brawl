#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *fn_8022EFF8(unsigned int);

u8 *fn_8024E864(int arg0, unsigned int arg1, int arg2, int arg3)
{
    u8 *p = fn_8022EFF8(2);
    int a, b, c;
    if (p == 0)
        return 0;
    a = arg0 | 0x2000;
    *(u16 *)(p + 4) = 0;
    *(u16 *)(p + 2) = arg1 + 12;
    b = arg1 + 8;
    c = arg1 + 4;
    p[8] = a;
    p[9] = a >> 8;
    p[10] = b;
    p[11] = b >> 8;
    p[12] = c;
    p[13] = c >> 8;
    p[14] = 1;
    p[15] = 0;
    p[16] = arg2;
    p[17] = arg3;
    p[18] = arg1;
    p[19] = arg1 >> 8;
    return p;
}