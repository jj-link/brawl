#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 4;
    unsigned int value : 2;
};

extern "C" void fn_47_4EEC(Data* self, unsigned int value)
{
    self->value = value;
}
