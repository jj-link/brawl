#pragma force_active on
typedef unsigned int u32;

struct FtSonicFloatWork {
    char pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_123_A498(FtSonicFloatWork* work, u32 index, float value) {
    work->m_floatWorks[index] += value;
}
