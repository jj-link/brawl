#pragma force_active on
typedef unsigned int u32;

struct FtWolfWork {
    char pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_125_B2D0(FtWolfWork* work, u32 index, float value) {
    work->m_floatWorks[index] += value;
}
