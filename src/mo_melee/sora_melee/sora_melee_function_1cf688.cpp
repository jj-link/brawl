#pragma force_active on
typedef int s32;

extern "C" void* fn_27_1CF688(char* self, s32 idx) {
    s32 v = *(s32*)(self + 8);
    s32 r = (v >> 29) + idx;
    if (r >= 2) {
        r -= 2;
    }
    return self + r * 12 + 12;
}
