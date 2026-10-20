#pragma force_active on
struct FnObj21 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" void fn_27_92768(FnObj21 *self)
{
    self->flags |= 0x2;
}
