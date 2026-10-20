#pragma force_active on
extern "C" {

class A {
    unsigned m_x;
    unsigned m_y;
    unsigned m_z;
};

class B {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

class C : public A, public B {
};

void fn_27_1AA4C8(C* self) {
    self->v4();
}

}
