#pragma force_active on
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual int get();
};
struct A {
    Inner** m_a;
    Inner** m_b;
};
struct B {
    int pad;
    unsigned m_flags;
};
extern "C" void fn_803008BC(A*, B*, unsigned);

extern "C" void fn_803021C0(const A* self, B* b, unsigned c) {
    Inner** p = self->m_a;
    b->m_flags = 0;
    if ((*p)->get() == 5) {
        b->m_flags |= 1;
    }
    if ((*self->m_b)->get() == 5) {
        b->m_flags |= 2;
    }
    fn_803008BC(const_cast<A*>(self), b, c);
}