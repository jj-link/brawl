#pragma force_active on
typedef unsigned int u32;

class IFace {
public:
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
    virtual void v18();
    virtual bool f19(u32 id);
    virtual void v20();
    virtual void f21(u32 id);
};

struct Mid {
    char pad[0x64];
    IFace* iface;
};

struct Ctx {
    char pad[0xd8];
    Mid* mid;
};

extern "C" {
void fn_27_2FC0F8(void* a, Ctx* ctx) {
    if (ctx->mid->iface->f19(0x22000012)) {
        ctx->mid->iface->f21(0x22000012);
    }
}
}
