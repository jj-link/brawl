#pragma force_active on
class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class Outer {
public:
    char pad[0x28];
    Inner* m_inner;
};

extern "C" {
void fn_27_2EB40();

void fn_27_2A82C(Outer* p) {
    p->m_inner->f1();
    fn_27_2EB40();
}
}
