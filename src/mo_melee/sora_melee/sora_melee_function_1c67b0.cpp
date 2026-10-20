#pragma force_active on
typedef int s32;

extern "C" {
void* fn_27_1C67B0(char* p, s32 idx) {
    s32 v = *(s32*)(p + 0x18);
    s32 i = (v >> 25) + idx;
    if (i >= 0x20) {
        i -= 0x20;
    }
    return p + 0x1c + i * 12;
}
}
