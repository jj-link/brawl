#pragma force_active on
struct Entry {
    unsigned char data[12];
};

extern "C" Entry *fn_27_FE35C(Entry *base, int index)
{
    int bias = *(int *)((char *)base + 8) >> 30;
    int adjusted = bias + index;

    if (adjusted >= 1)
        adjusted -= 1;

    return (Entry *)((char *)base + adjusted * 12 + 12);
}
