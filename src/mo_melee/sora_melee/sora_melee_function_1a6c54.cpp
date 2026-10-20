#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 10;
        u32 b : 22;
    } flags;
};

extern "C" {
void fn_27_1A6C54(Obj* self, u32 v)
{
    self->flags.a = v;
}
}
