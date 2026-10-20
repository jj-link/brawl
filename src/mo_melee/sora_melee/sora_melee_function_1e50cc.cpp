#pragma force_active on
class Node {
public:
    int m_0;
    int m_4;
};

class Sub {
public:
    virtual void f0();
    virtual Node* f1();
    virtual void f2();
    virtual void f3();
};

class Outer {
public:
    char m_pad[0x10];
    Sub m_sub;
};

extern "C" {
int fn_27_1E50CC(Outer* p) {
    return p->m_sub.f1()->m_4;
}
}
