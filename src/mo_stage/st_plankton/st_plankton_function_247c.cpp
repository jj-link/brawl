#pragma force_active on
struct PlanktonData {
    unsigned char padding[0x188];
    unsigned int value;
    float amount;
};

extern "C" void fn_74_247C(PlanktonData* self, unsigned int* value, float* amount) {
    *value = self->value;
    *amount = self->amount;
}
