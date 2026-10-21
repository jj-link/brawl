#pragma force_active on
struct Data {
    unsigned int unused[2];
    unsigned int : 6;
    unsigned int field : 6;
    unsigned int : 20;
};

extern "C" void fn_27_FEDD0(Data* self, unsigned int value)
{
    self->field = value;
}
