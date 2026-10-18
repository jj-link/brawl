#pragma force_active on
typedef unsigned int u32;

struct FloatWorkHolder {
    char pad[0x14];
    float *m_floatWorks;
};

extern "C" void fn_109_9274(FloatWorkHolder *self, u32 index, float value) {
    self->m_floatWorks[index] -= value;
}
