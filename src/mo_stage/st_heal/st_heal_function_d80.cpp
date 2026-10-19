#pragma force_active on
struct HealData {
    unsigned char padding[0x188];
    int value;
    float amount;
};

extern "C" void fn_87_D80(HealData* self, int* value, float* amount) {
    *value = self->value;
    *amount = self->amount;
}
