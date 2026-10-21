#pragma force_active on
typedef unsigned int u32;

extern "C" u32 fn_27_1A24F0(const void *ptr)
{
    const u32 *p = (const u32 *)((const char *)ptr + 8);
    return (*p >> 16) & 1;
}
