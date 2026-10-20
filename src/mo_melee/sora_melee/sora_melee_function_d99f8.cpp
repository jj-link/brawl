#pragma force_active on
typedef int s32;

extern "C" {
void* fn_27_D99F8(char* p, s32 n) {
    s32 v = *(s32*)(p + 8) >> 24;
    s32 t = v + n;
    if (t >= 0x46) {
        t -= 0x46;
    }
    return p + (t << 3) + 0xc;
}
}
