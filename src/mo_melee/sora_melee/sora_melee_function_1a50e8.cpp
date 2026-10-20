#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 a;
    u32 b;
    u32 f : 5;
    u32 g : 27;
};

extern "C" {
void fn_27_1A50E8(Obj* p, u32 v) {
    p->f = v;
}
}
