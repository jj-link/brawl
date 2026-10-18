#pragma force_active on
typedef unsigned int u32;

struct FtFloatHolder {
    char m_pad[0x14];
    float *m_values;
};

extern "C" void fn_110_98F0(FtFloatHolder *self, float value, u32 index) {
    self->m_values[index] -= value;
}
