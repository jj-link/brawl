#pragma force_active on
struct TableOwner {
    unsigned char pad[0x24];
    void *table;
    int count;
};

extern "C" void *fn_41_159AC(TableOwner *, int);

extern "C" void *fn_41_15964(TableOwner *owner, int index)
{
    int offset = index - 14;

    if (offset < 0)
        return fn_41_159AC(owner, index);

    void *table = owner->table;
    if (table == 0)
        return 0;

    if (offset < 0 && offset >= owner->count)
        return 0;

    return (char *)table + (offset << 6);
}
