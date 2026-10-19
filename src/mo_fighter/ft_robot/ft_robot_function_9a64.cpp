#pragma force_active on
extern "C" const float lbl_120_rodata_8;

typedef unsigned int u32;

struct FtRobotWorkDivide {
    char pad[0x14];
    float *m_floatWorks;
};

extern "C" void fn_120_9A64(FtRobotWorkDivide *work, u32 index, float value) {
    if (lbl_120_rodata_8 != value) {
        work->m_floatWorks[index] /= value;
    }
}
