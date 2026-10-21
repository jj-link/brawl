#pragma force_active on

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual unsigned int v5();
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

struct Modules {
    char pad0[0x14];
    VObj* second;
    char pad1[0x70 - 0x18];
    VObj* first;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_115_F0A8(Accesser*);

extern "C" void fn_115_EF90(void*, Accesser* accesser) {
    switch (accesser->modules->first->v16()) {
    case 0x114:
        if (accesser->modules->second->v5() == 1u) {
            if (accesser->modules->second->v3() != 0) {
                fn_115_F0A8(accesser);
            }
        }
        break;
    }
}
