#include <types.h>
#pragma force_active on

struct Sub {
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
    virtual void v18();
};

extern "C" void fn_801C4968(u8* self) {
    Sub* sub = *reinterpret_cast<Sub**>(self + 0x10);
    *reinterpret_cast<s32*>(self + 0x1c) = 0;
    if (sub != 0) {
        sub->v16();
    }
}
