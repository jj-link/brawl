#include <types.h>
#pragma force_active on

template <typename ElementTy, typename IndexTy>
struct soArrayListUnit {
    u8 m_inUse : 1;
    ElementTy m_element;
    IndexTy m_prev;
    IndexTy m_next;
};

class Class_X {
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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual s32 capacity();
    virtual bool isFull();

    s32 getFreeIndex() const { return m_freeIndex; }

    s32 m_freeIndex : 7;
    s32 m_topIndex : 7;
    s32 m_lastIndex : 7;
    s32 m_size : 7;
    s32 m_rest : 4;
    soArrayListUnit<int, s8> m_units[16];
};

extern "C" s32 fn_27_25F218(Class_X* self, s32 idx) {
    if (self->isFull() == true)
        return -1;
    if (idx < 0) {
        s32 freeIndex = self->getFreeIndex();
        self->m_freeIndex = self->m_units[self->m_freeIndex].m_next;
        if (self->m_freeIndex > 0)
            self->m_units[self->m_freeIndex].m_prev = -1;
        self->m_size++;
        return freeIndex;
    }
    if (idx >= self->capacity())
        return -1;
    const soArrayListUnit<int, s8>& curr = self->m_units[idx];
    if (static_cast<bool>(curr.m_inUse) == true)
        return -1;
    s32 next = curr.m_next;
    s32 prev = curr.m_prev;
    if (prev < 0 && next < 0)
        self->m_freeIndex = -1;
    else if (prev < 0) {
        self->m_units[next].m_prev = -1;
        self->m_freeIndex = curr.m_next;
    } else if (next < 0)
        self->m_units[prev].m_next = -1;
    else {
        self->m_units[prev].m_next = next;
        self->m_units[next].m_prev = prev;
    }
    self->m_size++;
    return idx;
}
