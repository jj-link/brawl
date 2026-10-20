#pragma force_active on
struct FlagHolder {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" void fn_73_ACD0(FlagHolder *self)
{
    self->flags |= 0x00080000;
}
