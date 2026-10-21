#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int upper : 4;
    unsigned int value : 4;
    unsigned int lower : 24;
};

extern "C" void fn_27_1A7074(Object* self, unsigned int value)
{
    self->value = value;
}
