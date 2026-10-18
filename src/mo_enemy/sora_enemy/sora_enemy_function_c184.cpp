#pragma force_active on
struct FlagHolder {
    char pad[0x1c];
    unsigned int *table;
};

extern "C" {
void fn_41_C184(FlagHolder *self, unsigned int flags, unsigned int index)
{
    self->table[index] |= flags;
}
}
