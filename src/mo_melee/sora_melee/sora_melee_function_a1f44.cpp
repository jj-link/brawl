#pragma force_active on
struct Pad8 {
    int m_pad[2];
};

struct Elem : public Pad8 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void update();
};

struct Holder {
    int m_pad0[2];
    int m_a;
    int m_b;
    int m_pad1[3];
    Elem* m_elems[3];
};

extern "C" {
void fn_27_A1F44(Holder* self) {
    for (int i = 0; i < 3; i++) {
        if (self->m_elems[i]) {
            self->m_elems[i]->update();
        }
    }
    self->m_a = 0;
    self->m_b = 0;
}
}
