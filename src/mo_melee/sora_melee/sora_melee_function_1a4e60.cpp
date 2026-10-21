#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 10;
    unsigned int value : 5;
    unsigned int : 17;
};

extern "C" void fn_27_1A4E60(Data* self, unsigned int value)
{
    self->value = value;
}
