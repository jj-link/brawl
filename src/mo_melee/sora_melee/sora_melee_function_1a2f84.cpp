#pragma force_active on
typedef unsigned int u32;

struct fn27Bits {
    u32 hi : 6;
    u32 f : 6;
    u32 lo : 20;
};

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    fn27Bits flags;
};

extern "C" {
void fn_27_1A2F84(fn27Obj* self, u32 v)
{
    self->flags.f = v;
}
}
