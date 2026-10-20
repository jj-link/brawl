#pragma force_active on
typedef int s32;

extern "C" char* fn_27_1B0BC0(char* self, s32 idx) {
    s32 n = (*(s32*)(self + 8) >> 26) + idx;
    if (n >= 0x11) {
        n -= 0x11;
    }
    return self + 0xC + n * 16;
}
