#pragma force_active on
class soWorkB {
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
    virtual void v13();
    virtual void v14();
    virtual void v15(void* p);
};

class soWorkA {
public:
    char pad[0x40];
    soWorkB* m_b;
};

class soWorkOuter {
public:
    char pad[0xd8];
    soWorkA* m_a;
};

extern "C" {
void fn_27_18453C(void* unused, soWorkOuter* p) {
    p->m_a->m_b->v15(p);
}
}
