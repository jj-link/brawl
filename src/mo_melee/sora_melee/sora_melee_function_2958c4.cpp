#pragma force_active on
typedef int s32;

extern "C" void* fn_27_2958C4(void* self, s32 idx) {
    s32 t = *(s32*)((char*)self + 8) >> 27;
    s32 n = t + idx;
    if (n >= 14) {
        n -= 14;
    }
    return (char*)self + (n << 2) + 12;
}
