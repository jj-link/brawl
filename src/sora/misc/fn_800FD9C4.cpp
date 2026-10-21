#pragma force_active on
struct A {
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
    virtual void v13(int arg);
};

struct Inner {
    char pad[0x10];
    int m_val;
};

struct Outer {
    A* m_a;
    char pad[8];
    Inner* m_ptr;
    char pad2[4];
    A* m_b;
};

extern A* lbl_805A030C;

extern "C" void fn_800FD9C4(Outer* p) {
    int arg = p->m_ptr->m_val;
    if (p->m_a == 0) {
        lbl_805A030C->v13(arg);
    } else {
        p->m_b->v13(arg);
    }
}
