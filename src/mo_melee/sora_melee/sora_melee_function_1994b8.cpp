#pragma force_active on
extern "C" void fn_27_1994B8(void *p)
{
    unsigned int *flags = (unsigned int *)((char *)p + 8);
    *flags &= ~0x00080000u;
}
