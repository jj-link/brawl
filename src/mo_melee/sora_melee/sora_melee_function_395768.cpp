#pragma force_active on
struct Object
{
    unsigned int padding[2];
    unsigned int value : 4;
    unsigned int remaining : 28;
};

extern "C" void fn_27_395768(Object* self, unsigned int value)
{
    self->value = value;
}
