#pragma force_active on
union Word {
    unsigned char bytes[4];
    unsigned int integer;
};

struct MetalGearData {
    unsigned char padding[0x188];
    Word value;
    float amount;
};

extern "C" void fn_71_2458(MetalGearData* self,
                          Word* value,
                          float* amount) {
    *value = self->value;
    *amount = self->amount;
}
