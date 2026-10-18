#pragma force_active on
struct FtZakoWork {
    char pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_126_75B4(FtZakoWork* work, unsigned int index, float value) {
    work->m_floatWorks[index] += value;
}
