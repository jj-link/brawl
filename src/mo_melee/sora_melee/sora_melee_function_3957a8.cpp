#pragma force_active on
extern "C" void fn_27_3957A8(void *p)
{
    unsigned int value = *(unsigned int *)((char *)p + 8);
    value |= 0x00080000;
    *(unsigned int *)((char *)p + 8) = value;
}
