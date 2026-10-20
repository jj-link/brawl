#pragma force_active on
typedef int s32;

extern "C" {
char* fn_27_1B0828(char* self, s32 idx) {
    s32 v = *(s32*)(self + 8);
    s32 sh = v >> 28;
    s32 n = sh + idx;
    if (n >= 4) {
        n -= 4;
    }
    return self + n * 0x48 + 0xC;
}
}
