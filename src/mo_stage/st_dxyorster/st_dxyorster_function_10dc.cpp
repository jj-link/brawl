#pragma force_active on
struct Obj {
    unsigned char pad[0x6c];
    unsigned char flags;
};

extern "C" void fn_76_10DC(Obj* self)
{
    self->flags |= 8;
}
