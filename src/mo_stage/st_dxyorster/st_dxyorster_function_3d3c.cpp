#pragma force_active on

extern "C" void fn_76_3D3C(void *self)
{
    unsigned int *p = (unsigned int *)((char *)self + 8);
    *p &= 0xFFFEFFFFu;
}
