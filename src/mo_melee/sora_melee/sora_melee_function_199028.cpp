#pragma force_active on
struct FlagHolder {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_199028(FlagHolder *self)
{
    self->flags |= 0x400000;
}
}
