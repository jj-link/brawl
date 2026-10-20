#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" s32 fn_27_FED08(const void* self) {
    u32 x = ((const u32*)self)[2];
    return ((s32)((x << 6) & 0xFE000000)) >> 26;
}
