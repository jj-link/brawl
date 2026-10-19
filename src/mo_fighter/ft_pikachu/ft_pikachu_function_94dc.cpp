#pragma force_active on
extern "C" void fn_98_10B10(void* accesser);

struct PikachuVirtBase {
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
    virtual int v16();
};

extern "C" void fn_98_94DC(int a, int b, void* accesser) {
    char* acc = (char*)accesser;
    char* mod = *(char**)(acc + 0xd8);
    PikachuVirtBase* obj = *(PikachuVirtBase**)(mod + 0x70);
    switch (obj->v16()) {
    case 0x11b:
        fn_98_10B10(accesser);
        break;
    }
}
