#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 4;
    unsigned int value : 4;
    unsigned int : 24;
};

extern "C" void fn_54_6984(Data* self, unsigned int value)
{
    self->value = value;
}
