#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern "C" {
void* fn_801AFAEC(void* arg0) {
    u8* p = (u8*)arg0;
    u32 idx = *(u16*)(p + 0x102);
    u32 n = *(u8*)(p + 0x101);
    u32 size = (idx * 0x30 + 0x1F) & ~0x1F;
    return (u8*)(*(u32*)(p + 0xF4)) + n * size;
}
}
