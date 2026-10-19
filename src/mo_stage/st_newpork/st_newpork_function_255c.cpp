#pragma force_active on
#pragma scheduling off

struct NewPorkData {
    unsigned char padding[0x188];
    unsigned int value;
    float amount;
};

extern "C" void fn_69_255C(const NewPorkData* self, unsigned int* value, float* amount)
{
    *value = self->value;
    *amount = self->amount;
}
