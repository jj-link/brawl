#pragma force_active on
typedef int s32;

extern "C" void* fn_27_D9368(char* p, s32 idx) {
    s32 r0 = *(s32*)(p + 8) >> 25;
    s32 i = r0 + idx;
    if (i >= 0x24) {
        i -= 0x24;
    }
    return p + i * 0x30 + 0xc;
}
