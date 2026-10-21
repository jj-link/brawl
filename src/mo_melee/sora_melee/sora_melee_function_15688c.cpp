#pragma force_active on
typedef unsigned int u32;
typedef int s32;

class IFace {
public:
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
    virtual u32 f17(u32 id);
};

struct Mid {
    char pad[0x64];
    IFace* iface;
};

struct Ctx {
    char pad[0xd8];
    Mid* mid;
};

extern "C" s32 fn_27_15688C(void* unused, Ctx* ctx) {
    s32 result = 0;
    if (ctx->mid->iface->f17(0x12000012) == 1U ||
        ctx->mid->iface->f17(0x12000018) == 1U ||
        ctx->mid->iface->f17(0x12000033) == 1U) {
        result = 1;
    }
    return result;
}
