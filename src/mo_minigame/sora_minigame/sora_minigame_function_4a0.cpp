#pragma force_active on
struct Entry
{
    void* value;
    void* unused;
};

struct Table
{
    int unused;
    Entry* entries;
    int count;
};

extern "C" void* fn_20_4A0(Table* table, const int* index)
{
    int i = *index;

    if (table->count > i) {
        return table->entries[i].value;
    }

    return 0;
}
