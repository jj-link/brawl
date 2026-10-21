#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int value : 6;
    unsigned int rest : 26;
};

extern "C" void fn_27_1D310(Data* self, unsigned int value)
{
    self->value = value;
}
