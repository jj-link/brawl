#pragma force_active on
extern "C" {
extern char lbl_80465F68[];
void fn_8019D88C(void* p, int flag);
}

struct C {
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
};

extern "C" void* fn_80199D94(C* arg0) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_80465F68;
        arg0->v15();
        if (arg0 != 0 && arg0 != 0) {
            fn_8019D88C(arg0, 0);
        }
    }
    return arg0;
}
