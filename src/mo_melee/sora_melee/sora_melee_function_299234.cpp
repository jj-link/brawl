#include <types.h>
#pragma force_active on

struct FakeBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 v4(u32 p);
};

extern "C" {
s32 fn_27_299234(void* unused, u8* obj) {
    void* a = *(void**)(obj + 0x60);
    void* b = *(void**)((u8*)a + 0xd8);
    FakeBase* c = *(FakeBase**)((u8*)b + 0x64);
    return c->v4(0x10000000);
}
}
