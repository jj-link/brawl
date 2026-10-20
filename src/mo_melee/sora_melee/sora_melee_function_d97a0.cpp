#pragma force_active on
typedef signed int s32;

extern "C" void* fn_27_D97A0(void* p, s32 idx) {
    s32 v = *(s32*)((char*)p + 8);
    s32 n = (v >> 28) + idx;
    if (n >= 5) {
        n -= 5;
    }
    return (char*)p + n * 0x90 + 0xc;
}
