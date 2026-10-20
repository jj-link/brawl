#include <types.h>
#pragma force_active on

class VBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual s32 v8();
};

extern "C" s32 fn_27_1DB794(void* p) {
    void* a = *(void**)((u8*)p + 0x60);
    void* b = *(void**)((u8*)a + 0xd8);
    VBase* c = *(VBase**)((u8*)b + 0xc4);
    return c->v8();
}
