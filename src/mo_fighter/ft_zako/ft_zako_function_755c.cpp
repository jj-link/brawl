#pragma force_active on
extern "C" const float lbl_126_rodata_8;

struct FtZakoFloatWork {
    char pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_126_755C(FtZakoFloatWork* work, float value, unsigned int index) {
    if (lbl_126_rodata_8 != value) {
        work->m_floatWorks[index] /= value;
    }
}
