#pragma force_active on
#include <types.h>

struct Item {
    virtual void slot0();
    virtual void slot1(s32 a, s32 b, void* c);
};

struct Holder {
    s32 pad[2];
    Item** list;
    u8 pad2[8];
    u32 count;
};

extern "C" void fn_801ADD4C(Holder* arg0, void* arg1) {
    u32 i = 0;
    s32 j = 0;
    while (i != arg0->count) {
        Item* item = arg0->list[j];
        i++;
        j++;
        item->slot1(7, 0, arg1);
    }
}
