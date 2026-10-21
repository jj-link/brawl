#include <types.h>
#pragma force_active on

struct Item {
    s32 unused;
    s32 value;
};

struct ItemInterface {
    virtual void unused0();
    virtual void unused1();
    virtual Item& at(s32 index);
};

struct Owner {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual s32 size();

    s32 padding[3];
    ItemInterface items;

    s32 find(s32 value) {
        if (value <= -1)
            return -1;

        s32 count = size();
        for (s32 i = 0; i < count; ++i) {
            if (value == items.at(i).value)
                return i;
        }
        return -1;
    }
};

extern "C" s32 fn_27_F8408(Owner* self, s32 value) {
    return self->find(value);
}
