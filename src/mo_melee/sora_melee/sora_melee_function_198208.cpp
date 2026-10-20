#pragma force_active on
extern "C" void fn_27_198208(unsigned int *p)
{
    unsigned int *flags = (unsigned int *)((char *)p + 8);
    *flags &= ~0x80000;
}
