#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
struct Item {
    u8 pad0[0x8BC];
    u32 f8BC;
    s32 f8C0;
    s32 f8C4;
    u32 f8C8;
    u8 pad1[0x3D28 - 0x8CC];
    u32 f3D28;
};
class Container {
public:
    virtual void v0();
    virtual Item** get(int i);
    virtual void v2();
    virtual s32 size();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void remove(int i);
};
struct Owner {
    u8 pad[0x6D8];
    Container list;
};
extern "C" {
void fn_27_2A7970(Owner* self, Item* item, s32 a, s32 b);
s32 fn_27_2A83B8(Owner* self, s32 arg1, s32 arg2, u32 arg3, u32 arg4) {
    Item* best = 0;
    s32 i;
    for (i = 0; i < self->list.size(); i++) {
        Item* item = *self->list.get(i);
        if (item != 0 &&
            (arg1 == item->f8C0 || arg1 == -1) &&
            (arg2 == 0 || arg2 == item->f8C4) &&
            (arg3 + 0x10000 == 0xFFFF || arg3 == item->f8C8) &&
            (arg4 + 0x10000 == 0xFFFF || arg4 == item->f3D28) &&
            (best == 0 || best->f8BC < item->f8BC)) {
            best = item;
        }
    }
    if (best == 0) {
        return 0;
    }
    if (best != 0) {
        for (i = 0; i < self->list.size(); i++) {
            if (*self->list.get(i) == best) {
                self->list.remove(i);
                fn_27_2A7970(self, best, 0, 1);
                break;
            }
        }
    }
    return 1;
}
}