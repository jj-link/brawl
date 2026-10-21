#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 2;
    unsigned int field : 2;
    unsigned int : 28;
};

extern "C" void fn_51_66F8(Data* self, unsigned int value)
{
    self->field = value;
}
