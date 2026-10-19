#pragma force_active on
extern "C" const float lbl_115_rodata_C;

typedef unsigned int u32;

struct FtDiddyFloatWork {
    char pad[0x14];
    float* m_floats;
};

extern "C" void fn_115_A354(FtDiddyFloatWork* work, u32 index, float value) {
    if (lbl_115_rodata_C != value) {
        work->m_floats[index] /= value;
    }
}
