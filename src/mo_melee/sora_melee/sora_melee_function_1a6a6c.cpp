#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int upper : 10;
    unsigned int value : 10;
    unsigned int lower : 12;
};

extern "C" void fn_27_1A6A6C(Object* self, unsigned int value)
{
    self->value = value;
}
