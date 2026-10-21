#include <types.h>
#pragma force_active on

class emSlotBase {
public:
    virtual void v0();
    virtual s32* getSlot(s32 idx);
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
    virtual s32 getCount();
};

class emSlotOwner {
public:
    u8 pad[0x28];
    emSlotBase slots;
};

extern "C" {
void fn_41_2C284(emSlotOwner* self, s32 a, s32 b) {
    s32 i;
    for (i = 0; i < self->slots.getCount(); i++) {
        s32* p = self->slots.getSlot(i);
        if (p != nullptr && p[0] == 0) {
            p[0] = a;
            p[1] = b;
            return;
        }
    }
}
}
