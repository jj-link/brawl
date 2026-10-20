#pragma force_active on
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" s32 fn_27_FE8B8(void* p) {
    u32 w = *(u32*)((u8*)p + 8);
    s32 t = (s32)((w << 4) & 0xF8000000);
    return t >> 28;
}
