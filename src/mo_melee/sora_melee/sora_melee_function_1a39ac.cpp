#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 10;
    unsigned int value : 10;
    unsigned int : 12;
};

extern "C" void fn_27_1A39AC(Object* self, unsigned int value)
{
    self->value = value;
}
