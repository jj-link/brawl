#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_27_295D2C(void *p)
{
    u32 *field = (u32 *)((char *)p + 8);
    *field &= ~0x00400000;
}
