#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_80242908(void*);

void fn_802465F8(u8* p, u32 arg1, u32 arg2) {
    u8 hi1 = (u8)((arg1 >> 8) & 0xFF);
    u8 hi2 = (u8)((arg2 >> 8) & 0xFF);
    *(u16*)(p + 2) = 7;
    *(u16*)(p + 4) = 0;
    p[8] = 0x28;
    p[9] = 0xC;
    p[10] = 4;
    p[11] = (u8)arg1;
    p[12] = hi1;
    p[13] = (u8)arg2;
    p[14] = hi2;
    fn_80242908(p);
}
