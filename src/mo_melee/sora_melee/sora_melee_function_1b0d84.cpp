#pragma force_active on
typedef int s32;

extern "C" void* fn_27_1B0D84(void* p, s32 idx) {
    s32* base = (s32*)p;
    s32 n = (base[2] >> 28) + idx;
    if (n >= 7) {
        n -= 7;
    }
    return (char*)p + n * 0x34 + 0xc;
}
