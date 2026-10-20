#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 6;
    unsigned int value : 6;
    unsigned int : 20;
};

extern "C" void fn_79_56AC(Data* self, unsigned int value)
{
    self->value = value;
}
