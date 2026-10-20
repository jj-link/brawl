#pragma force_active on
typedef unsigned int u32;

struct Fld {
    u32 hi : 12;
    u32 f : 6;
    u32 lo : 14;
};

struct Obj {
    u32 pad0;
    u32 pad1;
    Fld w;
};

extern "C" {
void fn_27_D1CD0(Obj *p, u32 v) {
    p->w.f = v;
}
}
