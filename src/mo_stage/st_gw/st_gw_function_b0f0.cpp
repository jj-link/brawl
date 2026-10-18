#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int value : 4;
    unsigned int remaining : 28;
};

extern "C" void fn_63_B0F0(Data* self, unsigned int value)
{
    self->value = value;
}
