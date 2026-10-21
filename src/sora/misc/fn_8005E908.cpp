#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;

extern "C" void fn_8005E908(void* p) {
    u8* obj = (u8*)p;
    *(u16*)(obj + 0x60) = 0xFFFF;
    *(u32*)(obj + 0x5c) = 0;
}
