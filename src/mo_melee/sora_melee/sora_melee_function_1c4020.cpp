#pragma force_active on
typedef int s32;

extern "C" char* fn_27_1C4020(char* self, s32 idx) {
    s32 v = *(s32*)(self + 0x18);
    s32 s = v >> 29;
    s32 t = s + idx;
    if (t >= 2) {
        t -= 2;
    }
    return self + t * 12 + 0x1c;
}
