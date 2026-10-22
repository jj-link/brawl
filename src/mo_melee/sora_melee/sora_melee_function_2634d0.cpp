#pragma force_active on
extern "C" void fn_27_581C();
#define H(p) virtual void p##0(); virtual void p##1();
#define E(p) H(p##x) H(p##y)
struct In;
struct A {
    E(a)E(b)E(c) H(d)
    virtual int s16(int, int);
    E(e)E(f)E(g)E(h)E(i)
    virtual void s37(int);
    E(j)E(k)E(l)E(m) H(n)
    virtual int s56();
};
struct B {
    E(a)E(b)E(c)E(d)E(e)E(f)E(g)E(h)E(i)E(j)E(k) virtual void z();
    virtual int s47();
    H(m) virtual void y();
    virtual void s51(int);
};
struct Base { char pad[0x3c]; };
struct Self : Base {
    E(a)E(b)E(c)E(d)E(e)E(f)E(g)E(h)E(i)E(j)E(k)E(l)E(m)E(n) H(p)
    virtual void s60(int, In*);
    virtual void s61(int, In*);
    char pad1[0xa4 - 0x40];
    unsigned char flags;
    char pad2[0x180 - 0xa5];
    In* in;
};
struct In { char pad[0x1c]; A* a; B* b; };
extern "C" void fn_27_2634D0(Self* self) {
    fn_27_581C();
    if ((unsigned)((self->flags >> 7) & 1) == 1) {
        A* q;
        int n = self->in->a->s56();
        for (int i = 0; i < n; i++) {
            if ((unsigned)self->in->a->s16(i, 0) == 1) {
                In* in = self->in;
                q = in->a;
                self->s60(i, in);
                q->s37(i);
            }
        }
    }
    if ((unsigned)((self->flags >> 6) & 1) == 1) {
        int n = self->in->b->s47();
        for (int i = 0; i < n; i++) {
            In* in = self->in;
            B* q = in->b;
            self->s61(i, in);
            q->s51(i);
        }
    }
}
