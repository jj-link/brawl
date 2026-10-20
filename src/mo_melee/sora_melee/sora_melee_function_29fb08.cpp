#include <types.h>
#pragma force_active on

class fnObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 v4(u32 x);
};

extern "C" u32 fn_27_29FB08(void* self, u8* p) {
    u8* a = *(u8**)(p + 0x60);
    u8* b = *(u8**)(a + 0xd8);
    fnObj* o = *(fnObj**)(b + 0x64);
    return o->v4(0x10000000);
}
