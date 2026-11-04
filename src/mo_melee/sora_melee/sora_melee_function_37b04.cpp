#include <types.h>
#pragma force_active on

class Item {
public:
    u8 pad[0x34];
    void* m34;
};

class List {
public:
    virtual void v0();
    virtual Item* v1(s32 flag);
};

class soCollisionGroup {
public:
    u8 pad[8];
    List* m8;
};

extern "C" {
void fn_27_37D7C(void*, void*, s32, s32);
u32 fn_27_38048(void*);
void fn_27_37FA8(void*);
}

extern "C" void __dt__16soCollisionGroupFv(soCollisionGroup* self, s32 flag) {
    Item* item = self->m8->v1(flag);
    fn_27_37D7C(item, item->m34, 1, 0);
    if (fn_27_38048(item) == 1) {
        fn_27_37D7C(item, (char*)item + 0x28, 1, 0);
    }
    Item* item2 = self->m8->v1(flag);
    fn_27_37FA8(item2);
}