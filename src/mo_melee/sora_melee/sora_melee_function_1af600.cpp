#include <types.h>
#pragma force_active on

struct FooItem {
    s32 unk0;
    s32 id;
};

class FooInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual FooItem* getItem(s32 index);
};

class FooOuter {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 getCount();

    u8 pad[0xC];
    FooInner m_inner;

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

extern "C" s32 fn_27_1AF600(FooOuter* self, s32 value) {
    return self->find(value);
}
