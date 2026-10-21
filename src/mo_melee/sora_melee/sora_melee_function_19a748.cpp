#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int field : 3;
    unsigned int rest : 29;
};

extern "C" void fn_27_19A748(Data* self, unsigned int value)
{
    self->field = value;
}
