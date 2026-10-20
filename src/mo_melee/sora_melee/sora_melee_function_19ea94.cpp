#pragma force_active on
typedef unsigned int u32;

struct Fld {
    u32 hi : 12;
    u32 f : 6;
    u32 lo : 14;
};

struct Obj {
    u32 a;
    u32 b;
    Fld fld;
};

extern "C" void fn_27_19EA94(Obj* p, u32 v) {
    p->fld.f = v;
}
