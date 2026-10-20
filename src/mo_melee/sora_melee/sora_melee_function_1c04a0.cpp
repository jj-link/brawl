#pragma force_active on
typedef int s32;

extern "C" {
void* fn_27_1C04A0(char* p, s32 idx) {
    s32 i = (*(s32*)(p + 0x18) >> 27) + idx;
    if (i >= 11) {
        i -= 11;
    }
    return p + i * 12 + 0x1c;
}
}
