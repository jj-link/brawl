#include <types.h>
#pragma force_active on

class fnMid {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setFlag(s32 a, u32 b);
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
    virtual void setName(u32 a);
};

struct fnHolder {
    char pad[0x64];
    fnMid* mid;
};

struct fnOwner {
    char pad[0xd8];
    fnHolder* holder;
};

extern "C" void fn_27_2DE1C0(s32 unused, fnOwner* owner) {
    owner->holder->mid->setFlag(0, 0x10000040);
    owner->holder->mid->setFlag(0, 0x10000041);
    owner->holder->mid->setName(0x1200003d);
}
