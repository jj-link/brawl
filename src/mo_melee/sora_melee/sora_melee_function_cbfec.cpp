#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 2;
    u32 b : 2;
    u32 rest : 28;
};

struct Holder {
    u32 pad0;
    u32 pad1;
    Bits bf;
};

extern "C" void fn_27_CBFEC(Holder *p, u32 v) {
    p->bf.b = v;
}
