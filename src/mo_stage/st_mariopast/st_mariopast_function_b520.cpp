#pragma force_active on
extern "C" void fn_48_B520(unsigned char *self)
{
    unsigned int *flags = (unsigned int *)(self + 8);
    *flags &= ~0x10u;
}
