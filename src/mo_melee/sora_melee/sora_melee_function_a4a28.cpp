#include <types.h>
#pragma force_active on

struct Elem {
    s32 id;
};

struct Inner {
    virtual void v0();
    virtual Elem* get(s32 idx);
    virtual void v2();
    virtual s32 getCount();
};

struct Outer {
    u8 pad[0x34];
    Inner* inner;
};

extern "C" Elem* fn_27_A4A28(Outer* self, s32 id, s32 n) {
    if (id == -1) {
        return self->inner->get(n);
    }
    s32 matches = 0;
    s32 count = self->inner->getCount();
    for (s32 i = 0; i < count; i++) {
        Elem* e = self->inner->get(i);
        if (id == e->id) {
            if (matches == n) {
                return self->inner->get(i);
            }
            matches++;
        }
    }
    return 0;
}
