#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad0 : 4;
    u32 f : 2;
    u32 rest : 26;
};

struct Obj {
    u32 pad[2];
    Bits bits;
};

extern "C" void fn_27_1D484(Obj *self, u32 v)
{
    self->bits.f = v;
}
