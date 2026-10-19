#pragma force_active on
struct FtYoshiFloatTable
{
    char pad[0x14];
    float *values;
};

extern "C" float fn_95_B8E8(const FtYoshiFloatTable *self, unsigned int index)
{
    return self->values[index];
}
