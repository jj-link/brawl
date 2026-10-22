#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;

extern void fn_80242908(void *a, void *b);

void fn_80244CD8(void *arg0, void *arg1, s8 arg2)
{
    u8 *d = (u8 *)arg0;
    u8 *s = (u8 *)arg1;
    *(u16 *)(d + 2) = 10;
    *(u16 *)(d + 4) = 0;
    d[8] = 10;
    d[9] = 4;
    d[10] = 7;
    d[11] = s[5];
    d[12] = s[4];
    d[13] = s[3];
    d[14] = s[2];
    d[15] = s[1];
    d[16] = s[0];
    d[17] = arg2;
    fn_80242908(arg0, arg1);
}
