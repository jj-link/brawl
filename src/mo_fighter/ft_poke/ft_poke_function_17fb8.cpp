#pragma force_active on

extern "C" void fn_27_13D34C(void*, void*, int);
extern "C" void fn_27_37794C(void*, int, int);

struct Obj4 {
    virtual void v0();
    virtual void v1();
    virtual void setA(float);
};

struct Obj10Base {
    char pad[8];
};

struct Obj10 : Obj10Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setB(float);
};

#define SLOTS10(p) \
    virtual void p##0(); \
    virtual void p##1(); \
    virtual void p##2(); \
    virtual void p##3(); \
    virtual void p##4(); \
    virtual void p##5(); \
    virtual void p##6(); \
    virtual void p##7(); \
    virtual void p##8(); \
    virtual void p##9();

struct SelfBase {
    char pad[0x3c];
};

struct Self : SelfBase {
    SLOTS10(a)
    SLOTS10(b)
    SLOTS10(c)
    SLOTS10(d)
    SLOTS10(e)
    SLOTS10(f)
    SLOTS10(g)
    SLOTS10(h)
    SLOTS10(i)
    SLOTS10(j)
    SLOTS10(k)
    SLOTS10(l)
    SLOTS10(m)
    SLOTS10(n)
    SLOTS10(o)
    SLOTS10(p)
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void dispatch(int);
};

#undef SLOTS10

extern "C" void fn_116_17FB8(char* self, char* arg1, int arg2) {
    Obj4* o1 = *(Obj4**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0xc);
    o1->setA(*(float*)(arg1 + 0xc));

    Obj10* o2 = *(Obj10**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x38);
    o2->setB(*(float*)(arg1 + 0x5c));

    reinterpret_cast<Self*>(self)->dispatch(arg2);

    fn_27_37794C(*(void**)(self + 0x60), arg2, 0x11e);
    if (arg2 == 6) {
        fn_27_13D34C(self, arg1, -1);
    }
}
