#pragma force_active on
typedef unsigned int u32;

struct Obj {
    char pad[8];
    u32 hi : 20;
    u32 mid : 10;
    u32 lo : 2;
};

extern "C" void fn_27_1A4230(Obj* p, u32 v) {
    p->mid = v;
}
