#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 4;
    u32 rest : 28;
};

struct Obj {
    u32 unk0;
    u32 unk4;
    Bits flags;
};

extern "C" void fn_27_419FC(Obj* self, u32 v) {
    self->flags.hi = v;
}
