#pragma force_active on
typedef struct FtWork {
    char pad[0x1c];
    unsigned int *table;
} FtWork;

extern "C" void fn_93_B240(FtWork *self, unsigned int index)
{
    self->table[index] = 0;
}
