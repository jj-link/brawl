#pragma force_active on
class fn_27_DA038_Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

class fn_27_DA038_Outer {
public:
    int unk0;
    int unk4;
    fn_27_DA038_Inner* m_inner;
};

extern "C" {
void fn_27_DA038(fn_27_DA038_Outer* p) {
    return p->m_inner->f4();
}
}
