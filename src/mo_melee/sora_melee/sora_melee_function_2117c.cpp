#pragma force_active on
class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
};

struct Obj {
    int m_0;
    Sub* m_sub;
    int m_8;
    int m_count;
};

extern "C" {
void fn_27_2117C(Obj* self) {
    if (self->m_sub != 0 && self->m_sub->f4() == 0) {
        self->m_sub->f7();
    } else if (self->m_count > 0) {
        self->m_count--;
    }
}
}
