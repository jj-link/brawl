#pragma force_active on
class Inner18 {
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
};

class Mid {
public:
    char pad[0x40];
    Inner18* m_40;
};

class Outer {
public:
    char pad[0xd8];
    Mid* m_d8;
};

extern "C" void fn_27_192094(void* unused, Outer* p) {
    p->m_d8->m_40->v15();
}
