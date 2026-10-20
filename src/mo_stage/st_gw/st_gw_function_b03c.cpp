#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int upper : 4;
    unsigned int flags : 2;
    unsigned int lower : 26;
};

extern "C" void fn_63_B03C(Data* self, unsigned int value)
{
    self->flags = value;
}
