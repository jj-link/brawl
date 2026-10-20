#pragma force_active on
extern "C" void fn_48_BBC8(void *arg)
{
    unsigned int *field = (unsigned int *)((char *)arg + 8);
    *field &= ~0x2000u;
}
