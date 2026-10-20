#pragma force_active on
#pragma scheduling off

struct IceData {
    unsigned char padding[0x188];
    unsigned int value;
    float amount;
};

extern "C" void fn_62_29C0(const IceData* self, unsigned int* value, float* amount) {
    *value = self->value;
    *amount = self->amount;
}
