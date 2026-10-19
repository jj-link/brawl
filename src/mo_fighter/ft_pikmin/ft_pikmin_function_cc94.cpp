#pragma force_active on
extern "C" const float lbl_113_rodata_C;

struct FloatWorkHolder {
    char pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_113_CC94(FloatWorkHolder* work, float value, unsigned int index) {
    if (lbl_113_rodata_C != value) {
        work->m_floatWorks[index] /= value;
    }
}
