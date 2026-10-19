#pragma force_active on
extern "C" const float lbl_93_rodata_C;

struct FtLinkWork {
    char pad[0x14];
    float* m_floats;
};

extern "C" void fn_93_B274(FtLinkWork* work, float value, unsigned int index) {
    if (lbl_93_rodata_C != value) {
        work->m_floats[index] /= value;
    }
}
