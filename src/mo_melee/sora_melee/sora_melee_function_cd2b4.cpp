#pragma force_active on
extern "C" void fn_27_CD2B4(void *p)
{
    unsigned int *w = (unsigned int *)((char *)p + 8);
    *w &= ~0x80000u;
}
