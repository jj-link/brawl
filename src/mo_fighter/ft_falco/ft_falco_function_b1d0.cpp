#pragma force_active on
extern "C" const float lbl_108_rodata_8;

struct FalcoFloatWork {
    char pad[0x14];
    float *m_floatWorks;
};

extern "C" void fn_108_B1D0(FalcoFloatWork *work, float value, unsigned int index) {
    if (lbl_108_rodata_8 != value) {
        work->m_floatWorks[index] /= value;
    }
}
