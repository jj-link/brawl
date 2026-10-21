#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int unused : 7;
    unsigned int field : 7;
    unsigned int rest : 18;
};

extern "C" void fn_27_CB638(Data* self, unsigned int value)
{
    self->field = value;
}
