#pragma force_active on
typedef unsigned int u32;

struct FtDonkeyFloatHolder {
    char pad[0x14];
    float *m_floatWorks;
};

extern "C" void fn_92_9A78(FtDonkeyFloatHolder *self, u32 index, float value)
{
    self->m_floatWorks[index] -= value;
}
