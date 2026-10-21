#pragma force_active on
struct Object
{
    unsigned int padding[2];
    unsigned int upper : 8;
    unsigned int value : 4;
    unsigned int lower : 20;
};

extern "C" void fn_27_1D0738(Object* self, unsigned int value)
{
    self->value = value;
}
