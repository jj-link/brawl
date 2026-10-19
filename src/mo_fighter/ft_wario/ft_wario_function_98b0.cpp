#pragma force_active on
extern "C" const float lbl_110_rodata_8;

struct FloatWorkHolder {
    char pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_110_98B0(FloatWorkHolder* work, float value, unsigned int index) {
    if (lbl_110_rodata_8 != value) {
        work->m_floatWorks[index] /= value;
    }
}
