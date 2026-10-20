#pragma force_active on
struct FloatArray {
    char padding[0x14];
    float* values;
};

extern "C" void fn_98_A0D8(FloatArray* self, int index, float value) {
    self->values[index] = value;
}
