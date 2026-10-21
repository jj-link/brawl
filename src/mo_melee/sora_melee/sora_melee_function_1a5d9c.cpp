#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 20;
    unsigned int value : 10;
    unsigned int : 2;
};

extern "C" void fn_27_1A5D9C(Data* self, unsigned int value)
{
    self->value = value;
}
