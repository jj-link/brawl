#pragma force_active on
struct IFace {
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
    virtual void call(unsigned long a, unsigned long b, short* c, short d);
};

extern "C" void fn_41_C518(IFace* p, unsigned long a, unsigned long b) {
    short x = 0;
    p->call(a, b, &x, -1);
}
