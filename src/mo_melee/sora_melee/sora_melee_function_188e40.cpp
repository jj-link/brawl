#pragma force_active on

class Iface {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void f7(int a, int b);
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void f21(int a);
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual int f34(int a, void* b);
};

struct Ctx {
    char pad0[0x64];
    Iface* m64;
    char pad1[0x70 - 0x68];
    Iface* m70;
};

struct Outer {
    char pad[0xd8];
    Ctx* ctx;
};

extern "C" {
void fn_27_188E40(void* a, Outer* o) {
    Ctx* c = o->ctx;
    Iface* obj = c->m64;
    if (c->m70->f34(0, c) != 0xED) {
        obj->f21(0x22000010);
        obj->f21(0x22000012);
        obj->f7(0, 0x20000000);
        obj->f7(0xA3, 0x20000000);
    }
}
}
