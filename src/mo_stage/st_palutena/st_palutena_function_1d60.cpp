#pragma force_active on
struct PalutenaData {
    unsigned char padding[0x188];
    unsigned int value;
    float amount;
};

extern "C" void fn_67_1D60(PalutenaData* self, unsigned int* value, float* amount) {
    *value = self->value;
    *amount = self->amount;
}
