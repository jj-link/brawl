#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct VObj {
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
    virtual void call17(u32 a, void* b);
};

extern "C" void fn_110_18FD0(void* unused, u8* p) {
    struct Local {
        u32 a;
        u8 b;
    };
    Local local;
    VObj* obj = *(VObj**)(*(char**)(p + 0xd8) + 0x54);
    local.a = 0x83d;
    local.b = 0;
    obj->call17(3, &local);
}
