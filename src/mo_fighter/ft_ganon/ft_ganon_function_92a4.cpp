#pragma force_active on
struct WorkFloats {
    char pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_109_92A4(WorkFloats* work, float value, unsigned int index) {
    work->m_floatWorks[index] = value;
}
