#include <types.h>
#pragma force_active on

struct Owner;

struct Item {
    virtual void v0();
    virtual void v1();
    virtual void remove(Owner*);
    virtual void detach(Owner*);
    virtual void v4();
    virtual void unlink(Owner*);
};

struct Owner {
    u8 pad0[0x6C];
    Item** listA;
    s32 countA;
    u8 pad74[4];
    Item** listB;
    s32 countB;
    u8 pad80[0x14C];
    Item** items;
    s32 count;
    u8 pad1D4[4];
    Item** listC;
    s32 countC;
};

extern "C" void fn_802E3D50(Owner* self) {
    for (s32 i = self->count - 1; i >= 0; --i) {
        Item* item = self->items[i];
        if (item) {
            item->remove(self);
        }
    }

    while (self->countA != 0) {
        (*self->listA)->detach(self);
    }

    while (self->countB != 0) {
        (*self->listB)->detach(self);
    }

    while (self->countC != 0) {
        (*self->listC)->unlink(self);
    }
}
