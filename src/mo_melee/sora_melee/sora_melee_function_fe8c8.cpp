#pragma force_active on
typedef unsigned int u32;

struct FE8Bits {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

struct FE8Obj {
    u32 unk0;
    u32 unk4;
    FE8Bits flags;
};

extern "C" void fn_27_FE8C8(FE8Obj* self, u32 v)
{
    self->flags.b = v;
}
