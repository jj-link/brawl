#pragma force_active on
struct EntryTable
{
    int padding[3];
    int entries[1];
};

extern "C" int* fn_27_1A6E8C(EntryTable* table, int index)
{
    return &table->entries[index];
}
