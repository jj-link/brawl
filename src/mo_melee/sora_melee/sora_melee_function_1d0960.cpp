#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    unsigned pad : 8;
    unsigned field : 4;
    unsigned rest : 20;
};

extern "C" void fn_27_1D0960(Obj* p, u32 v) {
    p->field = v;
}
