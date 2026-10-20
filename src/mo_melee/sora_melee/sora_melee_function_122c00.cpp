#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 hi : 6;
    u32 f : 6;
    u32 lo : 20;
};

extern "C" {
void fn_27_122C00(Obj* p, u32 v) {
    p->f = v;
}
}
