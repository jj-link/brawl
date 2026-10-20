#pragma force_active on
struct KartData {
    unsigned char padding[0x188];
    unsigned int value;
    float scalar;
};

extern "C" void fn_49_1114(KartData* self, unsigned int* value, float* scalar) {
    *value = self->value;
    *scalar = self->scalar;
}
