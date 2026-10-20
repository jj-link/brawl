#pragma force_active on
typedef int s32;

extern "C" void* fn_27_F34C0(void* p, s32 n) {
    s32 v = ((s32*)p)[6];
    s32 k = (v >> 29) + n;
    if (k >= 3) {
        k -= 3;
    }
    return (char*)p + k * 12 + 0x1c;
}
