#pragma force_active on
struct A { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
virtual void setA(float); virtual float getA(); };
struct B { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
virtual void f7(int, int); };
struct Inner { char pad[8]; A* a; };
struct MuObject { char pad[0x10]; B* b; Inner* in; void setFrameVisible(float f); };
void MuObject::setFrameVisible(float f) {
    if (f != in->a->getA()) {
        B* p = b;
        p->f7(2, 0);
        p->f7(5, 0);
    }
    in->a->setA(f);
}
