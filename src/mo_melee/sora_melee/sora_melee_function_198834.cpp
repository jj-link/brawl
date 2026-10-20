#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_198834(void* p) {
    return (s32)((*(u32*)((u8*)p + 8) & 0x0E000000u) << 4) >> 30;
}
