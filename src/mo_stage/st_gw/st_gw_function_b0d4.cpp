#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int upper : 8;
    unsigned int value : 4;
    unsigned int lower : 20;
};

extern "C" void fn_63_B0D4(Data* self, unsigned int value)
{
    self->value = value;
}
