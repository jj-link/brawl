#include <types.h>
#pragma force_active on

struct Item {
    s32 unk0;
    s32 id;
};

class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual Item* getItem(s32 index);
};

class Outer {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 getCount();

    u8 pad[0xC];
    Inner m_inner;

    s32 find(s32 value) {
        if (value <= -1)
            return -1;

        s32 count = getCount();
        for (s32 idx = 0; idx < count; idx++) {
            if (value == m_inner.getItem(idx)->id)
                return idx;
        }
        return -1;
    }
};

extern "C" s32 fn_27_C4EB4(Outer* self, s32 value) {
    return self->find(value);
}