#pragma force_active on
struct Obj70
{
    char pad[0x6c];
    unsigned char flags;
};

extern "C" void fn_52_36BC(Obj70 *self)
{
    self->flags |= 0x8;
}
