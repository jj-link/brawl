#pragma force_active on
struct Object
{
    unsigned int padding[2];
    unsigned int : 8;
    unsigned int value : 4;
    unsigned int : 20;
};

extern "C" void fn_63_B19C(Object* self, unsigned int value)
{
    self->value = value;
}
