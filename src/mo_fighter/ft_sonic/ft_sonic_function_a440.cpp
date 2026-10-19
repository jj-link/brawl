#pragma force_active on
extern "C" const float lbl_123_rodata_8;

typedef unsigned int u32;

struct FtSonicFloatWork {
    char pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_123_A440(FtSonicFloatWork* work, u32 index, float value) {
    if (lbl_123_rodata_8 != value) {
        work->m_floatWorks[index] /= value;
    }
}
