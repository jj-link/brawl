#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int value : 5;
    unsigned int remainder : 27;
};

extern "C" void fn_27_1A2598(Data* self, unsigned int value)
{
    self->value = value;
}
