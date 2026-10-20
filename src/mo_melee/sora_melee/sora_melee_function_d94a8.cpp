#pragma force_active on
extern "C" void *fn_27_D94A8(void *base, int index)
{
    int offset = *(int *)((char *)base + 8) >> 26;
    int result = offset + index;
    if (result >= 0x1b)
        result -= 0x1b;
    return (char *)base + result * 0x30 + 0x0c;
}
