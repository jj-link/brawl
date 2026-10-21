#pragma force_active on
typedef unsigned long u32;
typedef int s32;

struct Out { int x, y, z; };

struct Local {
    int a;
    int b;
    int kind;
    int id;
    Out out;
};

struct Iface {
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
    virtual void v16(int, Local*, int);
};

extern "C" void fn_93_10090(void* obj);

extern "C" Out fn_93_104C4(void* obj) {
    Iface* s = *(Iface**)(*(char**)((char*)obj + 0xd8) + 0x54);
    Local local;
    fn_93_10090(&local);
    local.kind = 7;
    local.id = 0x12d;
    s->v16(0, &local, 0);
    return local.out;
}
