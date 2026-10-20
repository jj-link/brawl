#pragma force_active on
typedef int s32;

extern "C" char* fn_27_F2ADC(char* p, s32 idx) {
    s32 n = (*(s32*)(p + 0x18) >> 28) + idx;
    if (n >= 5) {
        n -= 5;
    }
    return p + n * 12 + 0x1c;
}
