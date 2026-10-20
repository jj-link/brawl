#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Fn27Obj {
    u8 pad[8];
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_1E7E18(Fn27Obj* p, u32 v) {
    p->hi = v;
}
