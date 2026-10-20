#pragma force_active on
struct Entry
{
    unsigned char data[12];
};

extern "C" Entry *fn_27_FD300(void *base, int index)
{
    int shift = *(int *)((char *)base + 0x18) >> 29;
    int slot = shift + index;

    if (slot >= 2)
        slot -= 2;

    return (Entry *)((char *)base + 0x1C) + slot;
}
