#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int value : 4;
    unsigned int rest : 28;
};

extern "C" void fn_27_1CFDFC(Data* self, unsigned int value)
{
    self->value = value;
}
