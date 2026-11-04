#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_37D7C(void*, void*, s32, s32);
u32 fn_27_38048(void*);
}

struct Item {
    u8 pad0[0x28];
    u8 pad1[0xc];
    void* m34;
};

struct List {
    virtual void v0();
    virtual Item* get(s32 index);
    virtual void v2();
    virtual s32 size();
};

struct Owner {
    u8 pad[8];
    List* m8;
};

extern "C" void fn_27_36354(Owner* self) {
    Item* item;
    s32 i = 0;
    while (i < self->m8->size()) {
        item = self->m8->get(i);
        fn_27_37D7C(item, item->m34, 1, 0);
        if (fn_27_38048(item) == 1) {
            fn_27_37D7C(item, (u8*)item + 0x28, 1, 0);
        }
        i++;
    }
}
