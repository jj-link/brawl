#pragma force_active on
#include <types.h>

struct Inner {
    char pad[8];
    void* m8;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual int slot5(int);
    char pad[0x34];
    Inner* m38;
};

struct Context {
    char pad[0x78];
    s32 pending;
    u32 refcount;
    char pad2[4];
    s8 active;
};

struct Locals {
    s8 flag;
    void* ptr;
};

extern "C" void fn_802ED860(void*, Inner*);
extern "C" void fn_802EFE70(void*);
extern "C" void fn_802EFF2C(void*, s8*);
extern "C" void fn_802F8F98(void*, void*, int);

extern "C" int fn_802ED550(Context* self, Object_vptr_0* obj) {
    if (((const s32*)self)[0x7C / 4] != 0) {
        Locals msg;
        msg.flag = 9;
        msg.ptr = obj;
        fn_802EFF2C(self, &msg.flag);
        return 0;
    }
    u32 n = self->refcount;
    self->refcount = n + 1;
    if (obj->slot5((int)n) == 1) {
        if (obj->m38->m8 == self) {
            fn_802ED860(self, obj->m38);
        }
    }
    fn_802F8F98(self, obj, 1);
    u32 t = self->refcount - 1;
    self->refcount = t;
    if (t == 0 && self->pending != 0 && self->active == 0) {
        fn_802EFE70(self);
    }
    return 0x01000000;
}
