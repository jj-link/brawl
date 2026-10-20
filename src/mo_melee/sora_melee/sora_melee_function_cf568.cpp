#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 w0;
    u32 w1;
    u32 a : 12;
    u32 f : 6;
    u32 b : 14;
};

extern "C" void fn_27_CF568(Obj* o, u32 v) {
    o->f = v;
}
