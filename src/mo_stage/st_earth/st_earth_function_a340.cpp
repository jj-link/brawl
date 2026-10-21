#pragma force_active on
struct Object
{
    unsigned int padding[2];
    unsigned int value : 2;
    unsigned int remaining : 30;
};

extern "C" void fn_66_A340(Object* self, unsigned int value)
{
    self->value = value;
}
