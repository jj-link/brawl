#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad[2];
    u32 x : 3;
    u32 f : 3;
};

extern "C" void fn_27_19FD50(Obj* p, u32 v) {
    p->f = v;
}
