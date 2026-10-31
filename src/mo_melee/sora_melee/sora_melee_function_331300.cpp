#include <types.h>
#pragma force_active on

class fnInner {
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual u32 call(u32 arg);
};

struct fnSub {
    char pad[0x64];
    fnInner* inner;
};

struct fnOwner {
    char pad[0xd8];
    fnSub* sub;
};

extern "C" {
u32 fn_27_331300(u32 a, s32 b, u32 c, fnOwner* owner) {
    if (b == 2) {
        return a;
    }
    return owner->sub->inner->call(0x1200003d);
}
}
