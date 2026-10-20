#pragma force_active on
struct A {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual int v16() = 0;
};

struct B {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11(int a, int b) = 0;
};

struct Mid {
    char pad0[0x64];
    B* b;
    char pad1[8];
    A* a;
};

struct Work {
    char pad[0xd8];
    Mid* mid;
};

extern "C" void fn_27_171068(int unused, Work* work) {
    switch (work->mid->a->v16()) {
    case 0x71:
        work->mid->b->v11(0x20000001, 0);
        break;
    }
}
