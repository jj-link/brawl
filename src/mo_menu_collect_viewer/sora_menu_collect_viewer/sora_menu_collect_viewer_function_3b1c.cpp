#pragma force_active on
struct Vt {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual float s9();
};

struct C { char pad[0xc]; Vt* vt; };
struct B { char pad[0x14]; C* c; };
struct A { char pad[0x108]; B* b; };
struct Root { char pad[0x1ac]; A* a; };

extern const float lbl_6_rodata_1C4;

extern "C" bool fn_6_3B1C(Root* r) {
    return r->a->b->c->vt->s9() != lbl_6_rodata_1C4;
}
