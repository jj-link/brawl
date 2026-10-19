#pragma force_active on
typedef unsigned int u32;

extern "C" const float lbl_102_rodata_8;

struct KoopaFloatWork {
    char pad[0x14];
    float* m_floatWorks;
};

extern "C" void fn_102_91C0(KoopaFloatWork* work, u32 index, float value) {
    if (lbl_102_rodata_8 != value) {
        work->m_floatWorks[index] /= value;
    }
}
