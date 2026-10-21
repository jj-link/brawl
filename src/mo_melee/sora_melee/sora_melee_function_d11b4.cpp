#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 8;
    unsigned int value : 8;
    unsigned int : 16;
};

extern "C" void fn_27_D11B4(Data* self, unsigned int value)
{
    self->value = value;
}
