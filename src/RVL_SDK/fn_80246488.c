#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_80242908(void*);

void fn_80246488(void* p, u16 a, u16 b) {
    u8* ptr = (u8*)p;
    *(u16*)(ptr + 2) = 7;
    *(u16*)(ptr + 4) = 0;
    ptr[8] = 0x1E;
    ptr[9] = 0xC;
    ptr[0xA] = 4;
    ptr[0xB] = (u8)a;
    ptr[0xC] = (u8)(a >> 8);
    ptr[0xD] = (u8)b;
    ptr[0xE] = (u8)(b >> 8);
    fn_80242908(p);
}
