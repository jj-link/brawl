#pragma force_active on
struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};

struct Outer {
    int m_00;
    Inner* m_04;
    int m_08;
    int m_0C;
};

extern "C" void fn_27_C78A4(Outer* self) {
    if (self->m_04 != 0) {
        if (self->m_04->f4() == 0) {
            self->m_04->f7();
            return;
        }
    }
    if (self->m_0C > 0) {
        self->m_0C--;
    }
}
