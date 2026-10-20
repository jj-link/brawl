#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" void* fn_27_D8FA8(void* self, s32 idx) {
    s32 hi = ((s32*)self)[2] >> 28;
    s32 i = hi + idx;
    if (i >= 5) {
        i -= 5;
    }
    return (char*)self + (i << 2) + 12;
}
