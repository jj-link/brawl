#pragma force_active on
struct Obj
{
    unsigned char padding[8];
    unsigned int flags;
};

extern "C" void fn_74_6A4C(Obj* self)
{
    self->flags |= 0x02000000;
}
