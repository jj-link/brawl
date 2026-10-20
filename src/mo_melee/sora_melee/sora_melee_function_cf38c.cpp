#pragma force_active on
struct Fn27Obj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_CF38C(Fn27Obj* self)
{
    self->flags |= 0x2000;
}
}
