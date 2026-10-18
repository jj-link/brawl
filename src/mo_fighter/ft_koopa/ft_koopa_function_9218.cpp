#pragma force_active on
struct FtKoopaFloatTable {
    char pad[0x14];
    float *m_values;
};

extern "C" void fn_102_9218(FtKoopaFloatTable *self, unsigned int index, float value)
{
    self->m_values[index] += value;
}
