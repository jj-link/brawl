#pragma force_active on
struct Object
{
    unsigned char padding[0x520];
    unsigned int field_520;
    unsigned int field_524;
    unsigned int field_528;
};

extern "C" void fn_52_6D78(Object* self, unsigned int arg1, unsigned int arg2)
{
    self->field_520 = arg1;
    self->field_528 = arg2;
}
