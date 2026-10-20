#pragma force_active on
typedef int s32;

extern "C" char* fn_27_295D3C(char* self, s32 idx) {
    s32 r = (*(s32*)(self + 8) >> 29) + idx;
    if (r >= 3) {
        r -= 3;
    }
    return self + r * 0x68 + 0xC;
}
