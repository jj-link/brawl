#pragma force_active on
struct S {
    int a;
    short b, c, d, e;
    float f0 __attribute__((aligned(16)));
    float f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19;
    S() {}
    S(const S& o) { *this = o; }
    S& operator=(const S& o) {
        a = o.a; b = o.b; c = o.c; d = o.d; e = o.e;
        f0 = o.f0; f1 = o.f1; f2 = o.f2; f3 = o.f3; f4 = o.f4; f5 = o.f5;
        f6 = o.f6; f7 = o.f7; f8 = o.f8; f9 = o.f9; f10 = o.f10; f11 = o.f11;
        f12 = o.f12; f13 = o.f13; f14 = o.f14; f15 = o.f15; f16 = o.f16;
        f17 = o.f17; f18 = o.f18; f19 = o.f19;
        return *this;
    }
};
struct Obj { char pad[0x10]; S s; };
struct Mgr { char pad[8]; Obj** objs; };

extern "C" void fn_80098188(Mgr* m, int i, float v) {
    Obj* o = m->objs[i];
    S tmp = o->s;
    tmp.f6 = v;
    tmp.f7 = v;
    o->s = tmp;
}
