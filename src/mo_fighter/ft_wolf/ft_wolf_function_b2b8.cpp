#pragma force_active on
struct FnWork {
    unsigned char pad[0x14];
    float *m_floatWorks;
};

extern "C" void fn_125_B2B8(FnWork *work, unsigned int index, float value) {
    work->m_floatWorks[index] = work->m_floatWorks[index] - value;
}
