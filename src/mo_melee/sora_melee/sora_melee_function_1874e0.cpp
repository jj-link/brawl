#include <types.h>
#pragma force_active on

class fnVtblBase {
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
    virtual void v12(s32, s32);
};

extern "C" void fn_27_1874E0(void* self, u8* obj, s32 type) {
    if (type >= 0xEB) {
        goto call;
    }
    if (type >= 0xE9) {
        return;
    }
call:
    {
        u8* sub = *(u8**)(obj + 0xD8);
        fnVtblBase* target = *(fnVtblBase**)(sub + 0x40);
        target->v12(0, 0);
    }
}
