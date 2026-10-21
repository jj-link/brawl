#pragma force_active on
// main/fn_801760F4.c
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" void* fn_801760F4(const void* arg0, u32 arg1) {
    u32 off = *(const u16*)((const u8*)arg0 + 0x42);
    const u8* p = *(const u8* const*)(arg1 + off);

    while (p != 0 && *(const int*)(p + 0xc) != 1) {
        p = *(const u8* const*)(p + off);
    }

    return (void*)p;
}
