#include <types.h>
#pragma force_active on

struct Owner;

struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void update(Owner*);
};

struct Owner {
    u8 pad0[0x1CC];
    Item** items;
    s32 count;
};

extern "C" void fn_802E3ECC(Owner* self) {
    for (s32 i = self->count - 1; i >= 0; --i) {
        Item* item = self->items[i];
        if (item) {
            item->update(self);
        }
    }
}
