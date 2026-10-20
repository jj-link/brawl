#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual u32 v0();
    virtual u32 v1();
    virtual u32 v2();
    virtual u32 v3();
    virtual u32 v4();
    virtual u32 v5();
    virtual u32 v6();
    virtual u32 v7();
    virtual u32 v8();
    virtual u32 v9();
    virtual u32 v10();
};

extern "C" u32 fn_27_FCE3C(void* p) {
    Inner* in = (Inner*)((u8*)p + 0x10);
    return in->v8();
}
