#pragma force_active on
extern "C" void fn_27_B1348(void *p)
{
    unsigned int *flags = (unsigned int *)((char *)p + 8);
    *flags &= 0xFFFEFFFF;
}
