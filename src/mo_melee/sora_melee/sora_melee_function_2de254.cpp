#include <types.h>
#pragma force_active on

class WorkModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 get(u32 id);
    virtual void set(s32 value, u32 id);
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
    virtual s32 isFlag(u32 id);
    virtual void v18();
    virtual void offFlag(u32 id);
};

class OtherModule {
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
    virtual void v19();
    virtual void set(u32 value);
};

struct Holder {
    char pad0[0x64];
    WorkModule* work;
    char pad1[0x88 - 0x68];
    OtherModule* other;
};

struct Owner {
    char pad[0xd8];
    Holder* holder;
};

extern "C" void fn_27_2DE254(void* unused, Owner* owner) {
    if (owner->holder->work->isFlag(0x1200003d)) {
        u32 value = owner->holder->work->get(0x10000041);
        owner->holder->other->set(value);
    }
    owner->holder->work->set(0, 0x10000040);
    owner->holder->work->set(0, 0x10000041);
    owner->holder->work->offFlag(0x1200003d);
}
