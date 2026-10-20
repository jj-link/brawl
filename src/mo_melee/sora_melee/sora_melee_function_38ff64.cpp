#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

extern "C" {
void* fn_27_38FF64(u8* p, s32 idx)
{
    s32 v = *(s32*)(p + 0x18) >> 26;
    s32 n = v + idx;
    if (n >= 0x13) {
        n -= 0x13;
    }
    return p + n * 12 + 0x1c;
}
}
