#pragma force_active on
typedef int s32;

extern "C" void* fn_27_1B0584(void* self, s32 idx) {
    s32 v = *(s32*)((char*)self + 8);
    s32 t = (v >> 27) + idx;
    if (t >= 8) {
        t -= 8;
    }
    return (char*)self + t * 0x34 + 0xC;
}
