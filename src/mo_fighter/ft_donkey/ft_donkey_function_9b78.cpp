#pragma force_active on
struct FtDonkeyTable {
    char pad[0xc];
    void **entries;
};

extern "C" void *fn_92_9B78(const FtDonkeyTable *self, unsigned int index)
{
    return self->entries[index];
}
