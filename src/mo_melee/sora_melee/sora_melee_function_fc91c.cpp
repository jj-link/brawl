#pragma force_active on
typedef int s32;

extern "C" void* fn_27_FC91C(char* p, s32 n) {
    s32 v = *(s32*)(p + 0x18);
    s32 k = v >> 29;
    s32 m = k + n;
    if (m >= 3) {
        m -= 3;
    }
    return p + m * 12 + 0x1c;
}
