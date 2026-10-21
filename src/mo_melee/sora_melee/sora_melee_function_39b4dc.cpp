#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 get(u32 id);
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
    virtual void put(u32 id);
};

struct Owner {
    u8 pad[0x64];
    Obj* obj;
};

struct Outer {
    u8 pad[0xD8];
    Owner* owner;
};

extern "C" void fn_27_39B4DC(Outer* self, s32* arg1, s32* arg2) {
    Obj* o = self->owner->obj;
    if (arg1 != nullptr) {
        *arg1 = o->get(0x10000040);
    }
    if (arg2 != nullptr) {
        *arg2 = o->get(0x10000041);
    }
    o->put(0x1200003D);
}
