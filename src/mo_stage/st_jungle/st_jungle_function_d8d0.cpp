#pragma force_active on
extern "C" void fn_51_D8D0(void *object)
{
    unsigned int value = *(unsigned int *)((char *)object + 8);
    value |= 0x00400000;
    *(unsigned int *)((char *)object + 8) = value;
}
