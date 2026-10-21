#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_80198840(u32* dst, u32* src, u32 val) {
    *dst = val | *src;
}
