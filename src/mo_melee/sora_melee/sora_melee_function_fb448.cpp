#include <types.h>
#pragma force_active on

struct Inner {
    virtual void v0() = 0;
    virtual u32 getItem(u32 index) = 0;
    virtual void v2() = 0;
    virtual s32 getCount() = 0;
};

struct Visitor {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void visit(u32* p) = 0;
};

extern "C" void fn_27_FB448(u8* self, Visitor* visitor) {
    s32 count = reinterpret_cast<Inner*>(self + 0x10)->getCount();
    for (s32 i = 0; i < count; i++) {
        u32 item = reinterpret_cast<Inner*>(self + 0x10)->getItem(i);
        visitor->visit(&item);
    }
}
