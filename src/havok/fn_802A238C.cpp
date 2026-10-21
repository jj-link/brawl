#pragma force_active on
class Child {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
};

class Parent {
public:
    char pad[0x10];
    Child* m_child;
};

extern "C" {
void fn_802A238C(Parent* p) {
    if (p->m_child) {
        p->m_child->v10();
    }
}
}
