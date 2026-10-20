#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

struct Holder {
    u32 pad[2];
    Bits bits;
};

extern "C" {
void fn_27_395850(Holder *self, u32 v)
{
    self->bits.b = v;
}
}
