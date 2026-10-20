#pragma force_active on
extern "C" void fn_27_1CFC14(void *p)
{
    unsigned int value = *(unsigned int *)((char *)p + 8);
    value |= 0x00010000;
    *(unsigned int *)((char *)p + 8) = value;
}
