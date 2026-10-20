#pragma force_active on
typedef int s32;

extern "C" void* fn_27_293598(char* self, s32 idx) {
    s32 t = (*(s32*)(self + 0x18) >> 29) + idx;
    if (t >= 2) {
        t = t - 2;
    }
    return self + t * 12 + 0x1c;
}
