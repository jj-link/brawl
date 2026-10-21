#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int field : 10;
    unsigned int rest : 22;
};

extern "C" void fn_27_92728(Data* self, unsigned int value)
{
    self->field = value;
}
