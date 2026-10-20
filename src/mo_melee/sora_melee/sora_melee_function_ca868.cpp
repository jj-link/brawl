#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

extern "C" s32 fn_27_CA868(void* p) {
    u32 x = *(u32*)((u8*)p + 8);
    return ((s32)(((x << 5) | (x >> 27)) & 0xFC000000u)) >> 27;
}
