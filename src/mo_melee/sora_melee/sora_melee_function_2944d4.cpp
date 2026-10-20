#pragma force_active on
extern "C" {

struct A {
    virtual void ad() = 0;
    char pad[12];
};

struct B {
    virtual void b0() = 0;
    virtual void b1() = 0;
    virtual void b2() = 0;
    virtual void b3() = 0;
    virtual void b4() = 0;
    virtual void b5() = 0;
    virtual void b6() = 0;
    virtual void b7() = 0;
    virtual void m() = 0;
};

struct C : A, B {
};

void fn_27_2944D4(C* self) {
    B* b = (B*)((char*)self + 16);
    b->m();
}

}
