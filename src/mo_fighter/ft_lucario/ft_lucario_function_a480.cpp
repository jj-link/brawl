#pragma force_active on
struct FtLucarioFloatHolder {
    char pad[0x14];
    float *values;
};

extern "C" void fn_118_A480(FtLucarioFloatHolder *self, int index, float value) {
    self->values[index] += value;
}
