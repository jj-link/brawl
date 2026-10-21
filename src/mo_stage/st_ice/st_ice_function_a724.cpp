#pragma force_active on
struct Object {
    unsigned int pad[2];
    unsigned int : 8;
    unsigned int field : 4;
    unsigned int : 20;
};

extern "C" void fn_62_A724(Object* self, unsigned int value)
{
    self->field = value;
}
