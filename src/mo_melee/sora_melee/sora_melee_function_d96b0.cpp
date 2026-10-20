#pragma force_active on
extern "C" void *fn_27_D96B0(void *self, int offset)
{
    int shift = *(int *)((char *)self + 8) >> 24;
    int index = shift + offset;
    if (index < 0x6A)
        goto indexed;
    index -= 0x6A;
indexed:
    return (char *)self + index * 0x30 + 0xC;
}
