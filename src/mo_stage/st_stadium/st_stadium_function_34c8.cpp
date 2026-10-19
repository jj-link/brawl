#pragma force_active on
struct StadiumData {
    unsigned char padding[0x188];
    int value;
    float scalar;
};

extern "C" void fn_59_34C8(StadiumData* self, int* value, float* scalar) {
    *value = self->value;
    *scalar = self->scalar;
}
