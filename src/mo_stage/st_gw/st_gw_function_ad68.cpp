#pragma force_active on
struct Data {
    unsigned char padding[8];
    unsigned int flags : 2;
    unsigned int : 30;
};

extern "C" void fn_63_AD68(Data* self, unsigned int value)
{
    self->flags = value;
}
