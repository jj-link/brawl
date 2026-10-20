#pragma force_active on
typedef unsigned int u32;

struct fn_27_CF03C_S {
    u32 unk0;
    u32 unk4;
    u32 a : 6;
    u32 b : 6;
    u32 c : 20;
};

extern "C" void fn_27_CF03C(fn_27_CF03C_S* s, u32 v) {
    s->b = v;
}
