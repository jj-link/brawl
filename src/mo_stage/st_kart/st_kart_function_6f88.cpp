#pragma force_active on
struct KartState {
    unsigned char padding[8];
    unsigned int upper : 8;
    unsigned int value : 4;
    unsigned int lower : 20;
};

extern "C" void fn_49_6F88(KartState* self, unsigned int value)
{
    self->value = value;
}
