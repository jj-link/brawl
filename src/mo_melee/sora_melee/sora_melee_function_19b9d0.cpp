#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

extern "C" s32 fn_27_19B9D0(void* p) {
    u32 v = ((u32*)p)[2];
    s32 t = (s32)((v << 4) & 0xF8000000u);
    return t >> 28;
}
