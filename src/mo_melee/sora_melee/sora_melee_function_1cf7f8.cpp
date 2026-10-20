#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void* fn_27_1CF7F8(u8* p, s32 idx)
{
    s32 v = *(s32*)(p + 8) >> 27;
    s32 n = v + idx;
    if (n >= 10) {
        n -= 10;
    }
    return p + n * 12 + 12;
}
