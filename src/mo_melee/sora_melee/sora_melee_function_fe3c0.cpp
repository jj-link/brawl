#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int : 2;
    unsigned int field : 2;
    unsigned int : 28;
};

extern "C" void fn_27_FE3C0(Data* self, unsigned int value)
{
    self->field = value;
}
