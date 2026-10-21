#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int reserved : 4;
    unsigned int field : 2;
    unsigned int remaining : 26;
};

extern "C" void fn_68_6524(Data* self, unsigned int value)
{
    self->field = value;
}
