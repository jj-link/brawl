#pragma force_active on
typedef int s32;

extern "C" {
void* fn_27_D9688(char* p, s32 x) {
    s32 idx = (*(s32*)(p + 8) >> 24) + x;
    if (idx >= 0x73) {
        idx -= 0x73;
    }
    return p + idx * 0x30 + 0xc;
}
}
