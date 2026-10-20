#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad0;
    u32 pad1;
    struct {
        u32 a : 12;
        u32 f : 6;
        u32 b : 14;
    } w;
};

extern "C" void fn_27_1D05C8(Obj* p, u32 v) {
    p->w.f = v;
}
