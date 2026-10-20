#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 4;
    u32 rest : 28;
};

struct Obj {
    u32 pad[2];
    Bits bits;
};

extern "C" void fn_27_D2C8C(Obj *self, u32 val)
{
    self->bits.a = val;
}
