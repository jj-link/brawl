#pragma force_active on

typedef unsigned long u32;

extern "C" u32 fn_80204C30(u32, u32);

extern "C" u32 fn_801BFF28(const u32* arg0)
{
    u32 value = *arg0;
    u32 x = fn_80204C30(value, 0x20);
    if (x < 0x20)
        return 0;
    return (x - 0x20) & ~0x1F;
}
