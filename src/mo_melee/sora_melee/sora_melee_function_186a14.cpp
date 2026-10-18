#pragma force_active on
struct Obj {
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

struct Comp {
    char pad[0x40];
    Obj* obj;
};

struct Owner {
    char pad[0xd8];
    Comp* comp;
};

extern "C" {
void fn_27_186A14(int a, Owner* p) {
    p->comp->obj->v15(p);
}
}
