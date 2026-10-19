#pragma force_active on
typedef unsigned char u8;

struct Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Obj {
    int m_0;
    u8 m_flag;
    u8 m_pad[3];
    Base* m_child;
};

extern "C" void fn_10_BD70(Obj* self, int param) {
    if (self->m_child != 0) {
        self->m_child->f1();
    }
    if (param == 4) {
        self->m_flag |= 0x80;
    }
}
