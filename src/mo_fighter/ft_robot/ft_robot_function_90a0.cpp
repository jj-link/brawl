#pragma force_active on
struct P { int pad[2]; };
struct O : P {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void f(int);
};
struct C { char pad[0x9c]; O* o; };
struct B { char pad[0xd8]; C* c; };
struct A { char pad[0x60]; B* b; };
struct F { char pad; unsigned char flags; };

extern "C" void fn_120_90A0(A* a, int, int, F* f) {
    if (f->flags & 8) {
        a->b->c->o->f(1);
    }
}