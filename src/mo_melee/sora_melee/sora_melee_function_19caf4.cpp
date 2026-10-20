#pragma force_active on
struct Obj
{
    unsigned char pad[8];
    unsigned int field : 2;
};

extern "C" void fn_27_19CAF4(Obj* self, unsigned int value)
{
    self->field = value;
}
