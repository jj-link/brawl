#pragma force_active on
struct Data {
    unsigned char padding[8];
    unsigned int unused : 6;
    unsigned int flags : 6;
    unsigned int remaining : 20;
};

extern "C" void fn_27_CF504(Data* self, unsigned int value)
{
    self->flags = value;
}
