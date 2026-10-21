#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern "C" void* fn_80197184(void** arg0, u32 arg1)
{
    unsigned char* base = (unsigned char*)*arg0;
    u16 n = *(u16*)(base + 0x40);
    if (n <= arg1)
        return 0;

    s32 off = *(s32*)(base + 0x24);
    unsigned char* p;
    if (off != 0)
        p = base + off;
    else
        p = 0;

    p = p + arg1 * 0x5C;
    if (*(u32*)(p + 0xC) < n)
        return p;
    return 0;
}
