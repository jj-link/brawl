#pragma force_active on
typedef unsigned int u32;

struct FtWarioWork {
    char pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_110_98D8(FtWarioWork* work, u32 index, float value) {
    work->m_floatWorks[index] *= value;
}
