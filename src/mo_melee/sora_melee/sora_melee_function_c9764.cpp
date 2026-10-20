#pragma force_active on
struct Entry
{
    unsigned char data[0x0C];
};

struct TableEntry
{
    unsigned char data[0x2C];
};

extern "C" void *fn_27_C9764(TableEntry *table, int index)
{
    return table[index].data + 0x0C;
}
