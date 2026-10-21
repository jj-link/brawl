#include <types.h>
#pragma force_active on

struct Module {
    u8 pad[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual u8 getGroupNo(int);
    virtual void setGroupNo(u8, u16);
    virtual void* getFile(u32, u32);
};

struct ResourceId {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual u32 getId();
};

struct Access {
    u8 pad[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ResourceId* getAccesser();
};

struct Self {
    Module module;
    Access access;
    u8 pad[0x24 - 0x18];
    Module* other;
};

extern "C" void* fn_27_2BCCD0(Self* self, u32 arg1, u32 arg2) {
    u8 group = self->other->getGroupNo(0);
    Module* other = self->other;
    other->setGroupNo(self->module.getGroupNo(0), 0xFF);

    if (arg2 == 0xFFFF) {
        arg2 = self->access.getAccesser()->getId();
    }

    void* result = self->other->getFile(arg1, arg2);
    self->other->setGroupNo(group, 0xFF);
    return result;
}
