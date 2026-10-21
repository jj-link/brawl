#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_80242908(void *p);

void fn_80246444(void *arg0, u16 arg1, u16 arg2) {
    u8 *p = (u8 *)arg0;
    u8 hi = (u8)((arg1 >> 8) & 0xFF);
    u8 hi2 = (u8)((arg2 >> 8) & 0xFF);

    *(u16 *)(p + 0x2) = 7;
    *(u16 *)(p + 0x4) = 0;
    p[0x8] = 0x1C;
    p[0x9] = 0x0C;
    p[0xA] = 0x04;
    p[0xB] = (u8)arg1;
    p[0xC] = hi;
    p[0xD] = (u8)arg2;
    p[0xE] = hi2;
    fn_80242908(arg0);
}
