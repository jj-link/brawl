#pragma force_active on
extern "C" void fn_66_A708(void *self)
{
    int *p = (int *)((char *)self + 8);
    *p |= 0x80000;
}
