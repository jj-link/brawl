#pragma force_active on
typedef int s32;

extern "C" void* fn_27_1AFA1C(void* self, s32 idx) {
    s32 r0 = ((s32*)self)[2] >> 28;
    s32 n = r0 + idx;
    if (n >= 6) {
        n -= 6;
    }
    return (char*)self + (n << 2) + 0xc;
}
