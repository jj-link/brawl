#pragma force_active on
extern "C" void fn_27_19A508(void *self)
{
    unsigned int value = *(unsigned int *)((char *)self + 8);
    value |= 0x00010000;
    *(unsigned int *)((char *)self + 8) = value;
}
