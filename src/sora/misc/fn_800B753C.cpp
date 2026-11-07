#pragma force_active on
struct A { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
virtual void setA(float); virtual float getA(); };
struct B { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
virtual void f7(int, int); };
struct Inner { char pad[8]; A* a8; A* aC; A* a10; A* a14; A* a18; };
struct MuObject { char pad[0x10]; B* b; Inner* in; };
extern "C" void fn_800B753C(MuObject* o, float f) {
    if (o->in->aC) {
        if (f != o->in->aC->getA()) { B* p = o->b; p->f7(2, 0); p->f7(5, 0); }
        o->in->aC->setA(f);
    }
    if (o->in->a8) {
        if (f != o->in->a8->getA()) { B* p = o->b; p->f7(2, 0); p->f7(5, 0); }
        o->in->a8->setA(f);
    }
    if (o->in->a10) {
        if (f != o->in->a10->getA()) o->b->f7(3, 0);
        o->in->a10->setA(f);
    }
    if (o->in->a14) {
        if (f != o->in->a14->getA()) o->b->f7(3, 0);
        o->in->a14->setA(f);
    }
    if (o->in->a18) {
        if (f != o->in->a18->getA()) o->b->f7(3, 0);
        o->in->a18->setA(f);
    }
}
