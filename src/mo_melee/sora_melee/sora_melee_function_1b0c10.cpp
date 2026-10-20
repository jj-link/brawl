#pragma force_active on
typedef int s32;

extern "C" {
char* fn_27_1B0C10(char* self, s32 idx);
}

extern "C" char* fn_27_1B0C10(char* self, s32 idx) {
    s32 t = *(s32*)(self + 8) >> 30;
    s32 r = t + idx;
    if (r >= 1) {
        r -= 1;
    }
    return self + (r << 4) + 12;
}
