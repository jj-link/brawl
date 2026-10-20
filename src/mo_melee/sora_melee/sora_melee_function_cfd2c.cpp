#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_27_CFD2C(void *p)
{
    u32 *w = (u32 *)p;
    w[2] &= ~0x400u;
}
