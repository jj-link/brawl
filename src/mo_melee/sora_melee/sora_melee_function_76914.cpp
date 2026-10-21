#pragma force_active on
extern "C" void fn_27_ABE4C(void* p);

class Inner {
public:
    virtual void v0();
    virtual void* v3(int idx);
    virtual void v4();
    virtual int v5();
};

class Outer {
public:
    int m_0;
    Inner* m_inner;
    virtual void dummy();
};

extern "C" {
void fn_27_76914(Outer* self, int idx) {
    if (idx != -1) {
        fn_27_ABE4C(self->m_inner->v3(idx));
    } else {
        for (int i = 0; i < self->m_inner->v5(); i++) {
            fn_27_ABE4C(self->m_inner->v3(i));
        }
    }
}
}
