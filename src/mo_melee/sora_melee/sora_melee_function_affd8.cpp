#pragma force_active on
extern "C" void *fn_27_AFFD8(void *p1, int p2)
{
    int value = *(int *)((char *)p1 + 0x18);
    int shift = value >> 27;
    int index = shift + p2;

    if (index >= 8)
        index -= 8;

    return (char *)p1 + index * 12 + 0x1C;
}
