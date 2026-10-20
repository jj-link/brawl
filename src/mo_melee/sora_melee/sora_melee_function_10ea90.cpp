#include <types.h>
#pragma force_active on

struct SoVirtBase {
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
    virtual void v17();
    virtual s16 target(u32* a, s32 b, u16* c, s32 d);
};

extern "C" {
s32 fn_27_10EA90(u8* p, u32 a, s8 b) {
    u16 z = 0;
    SoVirtBase* obj = *(SoVirtBase**)(p + 0x8);
    return obj->target(&a, -1, &z, (s32)b);
}
}
