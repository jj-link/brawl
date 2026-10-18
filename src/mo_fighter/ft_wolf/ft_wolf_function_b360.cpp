#pragma force_active on
typedef struct FtWolfWork {
    char pad[0xc];
    int *values;
} FtWolfWork;

extern "C" void fn_125_B360(FtWolfWork *self, int value, unsigned int index)
{
    self->values[index] *= value;
}
