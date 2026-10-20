#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 5;
    u32 rest : 27;
};

extern "C" void fn_27_1A4DDC(Obj* p, u32 v) {
    p->hi = v;
}
