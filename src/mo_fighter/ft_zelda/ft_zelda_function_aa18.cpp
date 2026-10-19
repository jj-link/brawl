#pragma force_active on
extern "C" const float lbl_104_rodata_8;

typedef struct FloatWorkHolder {
    char pad[0x14];
    float *floatWorks;
} FloatWorkHolder;

extern "C" void fn_104_AA18(FloatWorkHolder *work, unsigned int index, float value) {
    if (lbl_104_rodata_8 != value) {
        work->floatWorks[index] /= value;
    }
}
