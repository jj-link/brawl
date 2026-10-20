#pragma force_active on
extern "C" void fn_67_4F7C(void *self)
{
    unsigned int *p = (unsigned int *)self + 2;
    *p = *p & ~0x02000000;
}