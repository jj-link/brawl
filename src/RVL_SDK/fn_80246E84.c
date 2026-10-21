#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_80242908(void *);

void fn_80246E84(void *arg0, int arg1)
{
    u8 *p = (u8 *)arg0;

    *(u16 *)(p + 2) = 4;
    *(u16 *)(p + 4) = 0;
    p[8] = 0x45;
    p[9] = 0xC;
    p[10] = 1;
    p[11] = arg1;

    fn_80242908(arg0);
}
