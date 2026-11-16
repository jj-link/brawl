#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4(s32 id);
};

struct Data {
    s32 unk0;
    char pad[0xc];
    s32 unk10;
};

struct Inner {
    char pad[0x64];
    Object_vptr_0* acc;
};

struct Owner {
    char pad[0xd8];
    Inner* inner;
};

struct Actor {
    char pad[0x60];
    Owner* owner;
};

extern "C" {
extern char g_ftCommonDataAccesser[];
Data* fn_27_14954C(void*, s32);

s32 fn_27_39FA04(Actor self) {
    Owner* owner = self.owner;
    Inner* inner = owner->inner;
    s32 cur = inner->acc->slot4(0x10000009);
    Data* d = fn_27_14954C(g_ftCommonDataAccesser, cur);
    s32 q = self.owner->inner->acc->slot4(0x10000005) / d->unk10;

    if (q < 0) {
        q = 0;
    } else if (q >= d->unk0) {
        q = d->unk0;
    }

    return q;
}
}