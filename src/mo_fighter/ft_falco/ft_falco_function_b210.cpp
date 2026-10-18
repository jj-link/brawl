#pragma force_active on
typedef unsigned int u32;

struct FtFloatWorkHolder
{
    char pad[0x14];
    float *m_floatWorks;
};

extern "C" void fn_108_B210(FtFloatWorkHolder *self, float value, u32 index)
{
    self->m_floatWorks[index] -= value;
}
