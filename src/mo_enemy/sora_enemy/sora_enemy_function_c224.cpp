#pragma force_active on
typedef struct FloatTableOwner {
    char pad[0x14];
    float *table;
} FloatTableOwner;

extern "C" float fn_41_C224(FloatTableOwner *self, int index)
{
    return self->table[index];
}
