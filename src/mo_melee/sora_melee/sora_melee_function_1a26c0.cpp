#pragma force_active on
typedef unsigned int u32;

struct BitField8 {
    u32 pad : 4;
    u32 f : 4;
    u32 rest : 24;
};

struct Holder {
    u32 w0;
    u32 w1;
    BitField8 bf;
};

extern "C" void fn_27_1A26C0(Holder* self, u32 v) {
    self->bf.f = v;
}
