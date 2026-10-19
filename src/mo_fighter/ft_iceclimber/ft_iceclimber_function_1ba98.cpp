#pragma force_active on
struct Local {
    unsigned int a;
    unsigned char b;
};

struct VBase {
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
    virtual void target(int, void*);
};

extern "C" {
void fn_105_1BA98(unsigned char* self) {
    Local local;
    local.a = 0x45c;
    local.b = 0;
    unsigned char* c = *(unsigned char**)(*(unsigned char**)(*(unsigned char**)(self + 0x60) + 0xd8) + 0x54);
    ((VBase*)c)->target(3, &local);
}
}
