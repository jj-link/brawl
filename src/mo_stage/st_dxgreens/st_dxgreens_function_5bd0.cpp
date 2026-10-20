#pragma force_active on
struct FnState {
    int field0;
    int field4;
    unsigned int flags;
};

extern "C" void fn_79_5BD0(FnState *self)
{
    self->flags |= 0x80000;
}
