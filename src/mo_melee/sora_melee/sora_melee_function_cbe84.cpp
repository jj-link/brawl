#pragma force_active on
struct Fn27Obj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_CBE84(Fn27Obj *self)
{
    self->flags &= ~0x80000u;
}
}
