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
    virtual u32 getId(u32 a, void* b);
};

class fnMid {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setFlag(s32 a, u32 b);
};

struct fnHolder {
    char pad[0x54];
    fnInner* inner;
    char pad2[0xc];
    fnMid* mid;
};

struct fnOwner {
    char pad[0xd8];
    fnHolder* holder;
};

extern "C" void fn_27_396E60(void*, fnOwner* owner) {
    fnHolder* holder = owner->holder;
    fnInner* inner = holder->inner;
    fnMid* mid = holder->mid;
    mid->setFlag(inner->getId(0, holder), 0x20000009);
    owner->holder->mid->setFlag(0, 0x2000000A);
    owner->holder->mid->setFlag(0, 0x2000000B);
}
