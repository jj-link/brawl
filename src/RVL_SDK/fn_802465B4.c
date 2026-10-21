#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_80242908(void *a, void *b);

void fn_802465B4(void *arg0, void *arg1)
{
    u8 *d = (u8 *)arg0;
    u8 *s = (u8 *)arg1;
    *(u16 *)(d + 2) = 6;
    *(u16 *)(d + 4) = 0;
    d[8] = 0x24;
    d[9] = 0xC;
    d[10] = 3;
    d[11] = s[2];
    d[12] = s[1];
    d[13] = s[0];
    fn_80242908(arg0, arg1);
}
