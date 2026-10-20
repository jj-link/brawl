#pragma force_active on
struct Obj
{
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" void fn_79_5B1C(Obj* self)
{
    self->flags |= 0x02000000u;
}
