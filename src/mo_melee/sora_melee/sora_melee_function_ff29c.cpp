#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 6;
    unsigned int field : 3;
    unsigned int : 23;
};

extern "C" void fn_27_FF29C(Object* self, unsigned int value)
{
    self->field = value;
}
