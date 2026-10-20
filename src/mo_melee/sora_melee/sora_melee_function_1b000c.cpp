#pragma force_active on
typedef int s32;

extern "C" void* fn_27_1B000C(char* self, s32 idx) {
    s32 n = (*(s32*)(self + 8) >> 26) + idx;
    if (n >= 16) {
        n -= 16;
    }
    return self + (n << 4) + 12;
}
