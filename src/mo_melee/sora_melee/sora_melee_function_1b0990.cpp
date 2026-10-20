#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

extern "C" void *fn_27_1B0990(void *p, s32 index)
{
    s32 value = *(s32 *)((u8 *)p + 8) >> 22;
    if (value + index >= 0x11D)
        index = value + index - 0x11D;
    else
        index = value + index;
    return (u8 *)p + index * 4 + 0xC;
}
