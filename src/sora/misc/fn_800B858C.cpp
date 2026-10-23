#pragma force_active on
class Child {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

class Parent {
public:
    char pad[4];
    Child* m_child;
};

extern "C" {
void fn_800B858C(Parent* p) {
    if (p->m_child) {
        p->m_child->v1();
    }
}
}
