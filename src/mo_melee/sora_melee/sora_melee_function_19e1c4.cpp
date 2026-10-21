#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int field : 6;
    unsigned int rest : 26;
};

extern "C" void fn_27_19E1C4(Data* self, unsigned int value)
{
    self->field = value;
}
