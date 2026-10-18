#pragma force_active on
struct FloatHolder {
    char pad[0x14];
    float* data;
};

extern "C" void fn_99_8B10(FloatHolder* self, int index, float value) {
    self->data[index] -= value;
}
