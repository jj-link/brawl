#pragma force_active on
struct EntryBase
{
    int padding[2];
    int count;
};

extern "C" void *fn_27_FE4CC(EntryBase *base, int index)
{
    int count = base->count >> 30;
    int result = count + index;

    if (result >= 1)
        result--;

    return (char *)base + result * 12 + 12;
}
