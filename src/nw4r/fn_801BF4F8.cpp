#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
};

struct Link {
    Link* next;
    Link* prev;
};

struct Item : Object_vptr_0 {
    char pad04[0x3c];
    s32 value;
    char pad44[0x30];
    u8 priority;
    char pad75[0x5b];
    Link link;
};

struct Manager {
    s32 count;
    Link list;
    u16 limit;
};

extern "C" void fn_801BF4F8(Manager* self, int limit) {
    self->limit = limit;
    if (self->count > (u16)limit) {
        Link* link;
        s32 value;
        while (self->count > self->limit) {
            link = self->list.next;
            s32 best = 0x80;
            Item* selected = 0;
            while (link != &self->list) {
                Item* item = (Item*)((char*)link - 0xd0);
                value = item->priority;
                value = value + item->value;
                s32 clamped;
                if (value > 0x7f)
                    clamped = 0x7f;
                else if (value < 0)
                    clamped = 0;
                else
                    clamped = value;
                if (best > clamped) {
                    selected = item;
                    best = clamped;
                }
                link = link->next;
            }
            selected->slot8();
        }
    }
}
