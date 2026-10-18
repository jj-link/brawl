#pragma force_active on
struct EntryTable
{
    char pad[0x14];
    int base;
    char pad2[8];
    void** entries[1];
};

extern "C" void* fn_100_13548(EntryTable* self, void*, int index, int subindex)
{
    return self->entries[index - self->base][subindex];
}
