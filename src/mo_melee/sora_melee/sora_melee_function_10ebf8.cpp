#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_27_10EBF8(void *obj)
{
    u32 *field = (u32 *)((char *)obj + 8);
    *field |= 0x00010000;
}
