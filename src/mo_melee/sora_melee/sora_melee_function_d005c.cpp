#pragma force_active on
extern "C" void fn_27_D005C(void *p)
{
    unsigned int *flags = (unsigned int *)((char *)p + 8);
    *flags &= ~0x400u;
}
