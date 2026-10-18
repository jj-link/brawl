#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_27_21F4AC(u32* p, u32 bit) {
    if (bit >= 0x16) {
        return;
    }
    p[3] |= 1 << bit;
}
