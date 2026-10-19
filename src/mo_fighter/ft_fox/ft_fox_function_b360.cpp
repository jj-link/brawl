#pragma force_active on
typedef unsigned int u32;

extern "C" const float lbl_97_rodata_8;

extern "C" void fn_97_B360(char* work, float value, u32 index) {
    if (lbl_97_rodata_8 != value) {
        float* floats = *(float**)(work + 0x14);
        floats[index] /= value;
    }
}
