#pragma force_active on
struct V3 { float x, y, z; };
struct S;
extern "C" V3 fn_41_6270(S*, int);
extern "C" void fn_41_534C(V3*, const V3&);
extern "C" int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned int, unsigned int);

#define P1(n) virtual void n();
#define P4(n) P1(n##a) P1(n##b) P1(n##c) P1(n##d)
#define P8(n) P4(n##a) P4(n##b)
#define P16(n) P8(n##a) P8(n##b)
#define P32(n) P16(n##a) P16(n##b)
#define P64(n) P32(n##a) P32(n##b)

struct A {
    P4(x)
    virtual V3 f18();
    P8(y) P1(y2)
    virtual V3 f40(int);
    P1(z1) P1(z2) P1(z3)
    virtual void f50();
    P1(q1) P1(q2) P1(q3)
    virtual float f60();
};
struct W {
    P16(x) P1(x2)
    virtual int f4c(int);
};
struct B {
    int pad0, pad1;
    P16(x) P8(y)
    virtual void f68(int, V3*);
    P4(z)
    virtual void f7c(int, V3*);
    P1(q)
    virtual void f84(int, V3*);
};
struct M { int p0; B* b; int p8; A* a; char pad[0x54]; W* w; };
struct S {
    char pad[0x3c];
    P64(x) P16(y) P4(z) P1(z1)
    virtual int f15c();
};

extern "C" int fn_41_637C(S* self, int idx) {
    if (!self->f15c()) return 0;
    M* m = *(M**)((char*)self + 0x1b4);
    int r;
    A* a;
    B* b;
    a = m->a;
    b = m->b;
    V3 s;
    V3 v;
    if (idx == 0) {
        if (*((unsigned char*)self + 0xd8) == 1) {
            r = m->w->f4c(0x12000003);
            a->f50();
            fn_41_534C(&v, fn_41_6270(self, r));
        } else {
            r = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl((char*)self + 0xdc, 0x59e7, 0) != 0;
            a->f50();
            fn_41_534C(&v, fn_41_6270(self, r));
        }
        b->f7c(0, &v);
        float f = a->f60();
        s.z = f; s.y = f; s.x = f;
        b->f68(0, &s);
        V3 u;
        fn_41_534C(&u, a->f18());
        b->f84(0, &u);
    } else {
        fn_41_534C(&v, a->f40(idx));
        b->f7c(idx, &v);
    }
    return 1;
}
