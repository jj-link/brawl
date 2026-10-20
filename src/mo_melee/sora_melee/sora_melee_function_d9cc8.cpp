#pragma force_active on
extern "C" int *fn_27_D9CC8(int *base, int index)
{
    int offset = base[2] >> 25;
    int adjusted = offset + index;

    if (adjusted >= 0x2C)
        adjusted -= 0x2C;

    return (int *)((char *)base + adjusted * 0x18 + 0x0C);
}
