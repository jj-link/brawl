#include <types.h>
#pragma force_active on

class fn27Iface {
public:
    virtual u32 vf0();
    virtual u32 vf1();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual u32 vf4();
    virtual u32 vf5();
    virtual u32 vf6();
    virtual u32 vf7();
    virtual u32 vf8();
    virtual u32 vf9();
    virtual u32 vf10();
    virtual u32 vf11();
    virtual u32 vf12();
    virtual u32 vf13();
    virtual u32 vf14();
    virtual u32 vf15();
    virtual u32 vf16();
    virtual u32 vf17();
};

struct fn27Obj {
    u8 pad0[0x40];
    fn27Iface* iface;
};

struct fn27Ctx {
    u8 pad0[0xD8];
    fn27Obj* obj;
};

extern "C" {
u32 fn_27_186F68(u32 unused, fn27Ctx* ctx);
}

extern "C" u32 fn_27_186F68(u32 unused, fn27Ctx* ctx) {
    return ctx->obj->iface->vf15();
}
