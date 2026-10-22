#include <types.h>
#pragma force_active on

struct Manager;

struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void remove(Manager*);
};

struct Manager {
    u8 pad0[0x64];
    Item** items;
    s32 count;
};

extern "C" void fn_802E841C(Manager* self) {
    for (s32 i = self->count - 1; i >= 0; --i) {
        Item* item = self->items[i];
        if (item) {
            item->remove(self);
        }
    }
}
