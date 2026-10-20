#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
};

struct Obj {
    u32 w0;
    u32 w1;
    Flags f;
};

extern "C" {
void fn_27_19D434(Obj *p, u32 v) {
    p->f.b = v;
}
}
