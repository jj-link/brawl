#pragma force_active on
typedef int s32;

extern "C" char* fn_27_1B0850(char* p, s32 idx) {
    s32 v = *(s32*)(p + 8) >> 29;
    s32 n = v + idx;
    if (n >= 3) {
        n -= 3;
    }
    return p + n * 0x48 + 0xc;
}
