#include <types.h>
#pragma force_active on

struct Obj {
    virtual void slot0();
    virtual void slot1(int a, int b, int c);
};

struct Holder {
    u8 pad[4];
    Obj** items;
    u8 pad2[8];
    u32 count;
};

extern "C" void fn_801ADCC4(Holder* h, int arg1) {
    u32 i = 0;
    while (i != h->count) {
        Obj* o = h->items[i++];
        o->slot1(6, 0, arg1);
    }
}
