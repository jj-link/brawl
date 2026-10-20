#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" void* fn_27_D9B38(char* p, s32 i) {
    s32 n = (*(s32*)(p + 8) >> 27) + i;
    if (n >= 11) {
        n -= 11;
    }
    return p + n * 0x24 + 0xC;
}
