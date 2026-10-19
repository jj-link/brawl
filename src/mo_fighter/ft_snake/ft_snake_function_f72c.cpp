#pragma force_active on
extern "C" const float lbl_122_rodata_C;

extern "C" void fn_122_F72C(char* work, unsigned int index, float value) {
    if (lbl_122_rodata_C != value) {
        float* floats = *(float**)(work + 0x14);
        floats[index] /= value;
    }
}
