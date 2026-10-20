#pragma force_active on
typedef unsigned int u32;

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_19F588(Fn27Obj* self)
{
    self->flags &= ~0x00080000;
}
}
