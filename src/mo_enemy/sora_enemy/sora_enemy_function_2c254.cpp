#include <types.h>
#pragma force_active on

struct VObj {
    virtual u32 v0();
    virtual u32 v1();
    virtual u32 v2();
    virtual u32 v3();
    virtual u32 v4(u32 id);
};

extern "C" {
u32 fn_41_2C254(void* self) {
    void* a = *(void**)((char*)self + 0x6c);
    void* b = *(void**)((char*)a + 0xd8);
    VObj* c = *(VObj**)((char*)b + 0x64);
    return c->v4(0x10000005);
}
}
