#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
extern const float lbl_24_rodata_40;

void fn_24_1E70(void* self) {
    char* p = (char*)self;
    u32 flags = *(u8*)(p + 0x2c);
    float zero = lbl_24_rodata_40;
    *(u32*)(p + 0x50) = 0;
    flags = flags & ~2u;
    *(u8*)(p + 0x2c) = flags;
    *(u32*)(p + 0x54) = 0;
    *(u32*)(p + 0x58) = 0;
    *(float*)(p + 0x60) = zero;
    *(float*)(p + 0x64) = zero;
    *(u32*)(p + 0x68) = 0;
    *(u32*)(p + 0x6c) = 0;
    *(u8*)(p + 0x70) = 0;
    *(u8*)(p + 0x71) = 0;
    *(u8*)(p + 0x72) = 0;
    *(u8*)(p + 0x73) = 0;
    *(u32*)(p + 0x74) = 0;
    *(u32*)(p + 0x78) = 0;
    *(u32*)(p + 0x7c) = 0;
}
}
