#pragma force_active on
extern "C" const float lbl_121_rodata_C;

typedef unsigned int u32;

struct FtToonlinkWork {
    char pad[0x14];
    float* m_values;
};

extern "C" void fn_121_B270(FtToonlinkWork* work, u32 index, float value) {
    if (lbl_121_rodata_C != value) {
        work->m_values[index] /= value;
    }
}
