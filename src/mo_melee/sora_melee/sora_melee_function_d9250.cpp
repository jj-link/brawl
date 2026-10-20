#pragma force_active on
typedef int s32;

extern "C" char* fn_27_D9250(char* self, s32 idx) {
    s32 n = (*(s32*)(self + 8) >> 25) + idx;
    if (n >= 0x36) {
        n -= 0x36;
    }
    return self + n * 0x30 + 0xC;
}
