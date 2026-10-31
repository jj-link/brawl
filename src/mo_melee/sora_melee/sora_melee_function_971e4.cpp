#include <types.h>
#pragma force_active on

class soBase {
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
    virtual void v14(void* arg);
    virtual void v15();
    virtual void v16(void* arg);
};

struct soCtx {
    char pad[0x28];
    void* unk28;
};

extern "C" {
void fn_27_971E4(soBase* obj, s32* p, s32 unused, soCtx* ctx, s32 mode) {
    if (mode != 1) {
        return;
    }
    if (*p != 0x3c) {
        return;
    }
    return obj->v14(ctx->unk28);
}
}
