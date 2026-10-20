#pragma force_active on
typedef int s32;

extern "C" void* fn_27_1B13E8(char* p, s32 idx) {
    s32 t = *(s32*)(p + 8);
    s32 s = t >> 30;
    s32 n = s + idx;
    n = (n >= 1) ? n - 1 : n;
    return p + n * 0x30 + 0xc;
}
