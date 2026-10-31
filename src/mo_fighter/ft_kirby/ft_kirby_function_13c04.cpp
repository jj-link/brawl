#pragma force_active on
struct B { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual int f24(int a, bool b, bool c); };
struct M { char pad[0x88]; B* b; };
struct F { char pad[0xd8]; M* m; };
extern "C" int fn_96_13C04(int a, F* f, int id) {
    if (id == 0x12b) return a;
    return f->m->b->f24(2, 1, 1);
}