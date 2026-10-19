#pragma force_active on
extern "C" const float lbl_105_rodata_10;

struct FtWorkLayout {
    char pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_105_DCFC(FtWorkLayout* work, float value, unsigned int index) {
    if (lbl_105_rodata_10 != value) {
        work->m_floatWorks[index] /= value;
    }
}
