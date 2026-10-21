#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int value : 5;
    unsigned int rest : 27;
};

extern "C" void fn_27_199D48(Data* self, unsigned int value)
{
    self->value = value;
}
