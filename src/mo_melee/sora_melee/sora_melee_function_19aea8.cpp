#pragma force_active on
extern "C" void fn_27_19AEA8(void *self)
{
    unsigned int value = *(unsigned int *)((char *)self + 8);
    value &= 0xFFFEFFFFu;
    *(unsigned int *)((char *)self + 8) = value;
}
