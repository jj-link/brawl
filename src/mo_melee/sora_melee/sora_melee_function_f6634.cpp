#pragma force_active on
extern "C" void *fn_27_F6634(void *base, int index)
{
    int field = *(int *)((char *)base + 0x18);
    int adjusted = (field >> 30) + index;

    if (adjusted >= 1)
        adjusted--;

    return (char *)base + 0x1C + adjusted * 12;
}
