#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 12;
    unsigned int field : 6;
    unsigned int : 14;
};

extern "C" void fn_48_BE4C(Data* self, unsigned int value)
{
    self->field = value;
}
