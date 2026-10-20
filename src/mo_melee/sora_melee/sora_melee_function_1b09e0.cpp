#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" void* fn_27_1B09E0(char* p, u32 idx) {
    s32 v = *(s32*)(p + 8) >> 28;
    s32 i = v + (s32)idx;
    if (i >= 4) {
        i -= 4;
    }
    return p + (i << 4) + 12;
}
