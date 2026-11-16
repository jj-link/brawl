#include <types.h>
#pragma force_active on

class soKineticEnergy;

struct FooItem {
    s32 unk0;
    s32 id;
};

class FooInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual FooItem* getItem(s32 index) const;
};

template <typename T, int N>
class soInstanceManagerFullPropertyVector {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 getCount() const;

    u8 pad[0xC];
    FooInner m_inner;

    s32 find(s32 value) const {
        if (value <= -1)
            return -1;
        s32 count = getCount();
        for (s32 idx = 0; idx < count; idx++) {
            if (value == m_inner.getItem(idx)->id)
                return idx;
        }
        return -1;
    }

    s32 getIndex(s32 value) const;
};

template <typename T, int N>
s32 soInstanceManagerFullPropertyVector<T, N>::getIndex(s32 value) const {
    return find(value);
}

template s32 soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>::getIndex(s32) const;
