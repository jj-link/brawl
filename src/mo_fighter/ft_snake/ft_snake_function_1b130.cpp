#include <ft/fighter.h>
#pragma force_active on

extern "C" void fn_122_1AF04(Fighter* self);

struct VObjA {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
    virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3(); virtual void e4(); virtual void e5(); virtual void e6(); virtual void e7(); virtual void e8(); virtual void e9();
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3();
    virtual void callB(int, void*);
    virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7(); virtual void g8(); virtual void g9();
    virtual void h0(); virtual void h1(); virtual void h2(); virtual void h3(); virtual void h4(); virtual void h5(); virtual void h6(); virtual void h7(); virtual void h8(); virtual void h9();
    virtual void i0(); virtual void i1(); virtual void i2(); virtual void i3(); virtual void i4(); virtual void i5(); virtual void i6(); virtual void i7(); virtual void i8(); virtual void i9();
    virtual void j0(); virtual void j1(); virtual void j2(); virtual void j3(); virtual void j4(); virtual void j5(); virtual void j6(); virtual void j7(); virtual void j8(); virtual void j9();
    virtual void k0(); virtual void k1(); virtual void k2(); virtual void k3(); virtual void k4(); virtual void k5(); virtual void k6(); virtual void k7(); virtual void k8(); virtual void k9();
    virtual void l0(); virtual void l1(); virtual void l2(); virtual void l3(); virtual void l4(); virtual void l5(); virtual void l6();
    virtual unsigned int callA(); // slot 90
};

extern "C" void fn_122_1B130(Fighter* self) {
    void* mod = *(void**)((char*)self + 0xd8);
    VObjA* obj = *(VObjA**)((char*)mod + 0x54);
    unsigned int r = obj->callA();
    if (r == 1) {
        fn_122_1AF04(self);
    }
    void* mod2 = *(void**)((char*)self + 0xd8);
    VObjA* obj2 = *(VObjA**)((char*)mod2 + 0x70);
    obj2->callB(0, self);
}
