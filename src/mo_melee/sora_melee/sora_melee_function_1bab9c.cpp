#pragma force_active on
extern "C" void *fn_27_1BAB9C(void *p, int index)
{
    int field = *(int *)((char *)p + 0x18);
    int slot = field >> 29;
    int sum = slot + index;
    if (sum >= 2)
        sum -= 2;
    return (char *)p + sum * 0xC + 0x1C;
}
