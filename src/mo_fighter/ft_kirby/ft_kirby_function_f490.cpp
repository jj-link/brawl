#pragma force_active on
typedef unsigned int u32;

extern "C" const float lbl_96_rodata_8;

struct Fn96Work {
    char pad[0x14];
    float *floatWorks;
};

extern "C" void fn_96_F490(Fn96Work *work, u32 index, float value) {
    if (lbl_96_rodata_8 != value) {
        work->floatWorks[index] /= value;
    }
}
