#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int flags : 4;
    unsigned int rest : 28;
};

extern "C" void fn_27_295A2C(Data* self, unsigned int value)
{
    self->flags = value;
}
