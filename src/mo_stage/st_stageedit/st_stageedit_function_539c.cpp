#pragma force_active on
struct StageEditData {
    unsigned char padding[0x188];
    unsigned int value;
    float amount;
};

extern "C" void fn_85_539C(StageEditData* self, unsigned int* value, float* amount) {
    *value = self->value;
    *amount = self->amount;
}
