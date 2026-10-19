#pragma force_active on
extern const float lbl_101_rodata_8;

struct NessFloatTable {
    char pad[0x14];
    float* values;
};

extern "C" void fn_101_D3CC(NessFloatTable* self, int index, float divisor) {
    if (lbl_101_rodata_8 == divisor) {
        return;
    }
    self->values[index] = self->values[index] / divisor;
}
