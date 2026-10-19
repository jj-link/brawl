#pragma force_active on
extern "C" const float lbl_107_rodata_C;

struct FloatWork {
    unsigned char pad[0x14];
    float* values;
};

extern "C" void fn_107_C580(FloatWork* work, unsigned int index, float value) {
    if (lbl_107_rodata_C != value) {
        work->values[index] /= value;
    }
}
