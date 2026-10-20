#pragma force_active on
typedef int s32;

extern "C" void* fn_27_1B03CC(void* self, s32 idx) {
    s32 n = (*(s32*)((char*)self + 8) >> 29) + idx;
    if (n >= 2) {
        n -= 2;
    }
    return (char*)self + n * 0x60 + 0xc;
}
