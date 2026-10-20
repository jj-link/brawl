#pragma force_active on
extern "C" void *fn_27_3197FC(void *p, int index)
{
    int value = *(int *)((char *)p + 0x18);
    int nibble = value >> 28;
    int result = nibble + index;
    if (result >= 7)
        result -= 7;
    return (char *)p + 0x1C + result * 16;
}
