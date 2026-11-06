#include <types.h>
#pragma force_active on

class wnPikminPikmin;

template <typename ElementTy, typename IndexTy>
struct soArrayListUnit {
    u8 m_inUse : 1;
    ElementTy m_element;
    IndexTy m_prev;
    IndexTy m_next;
};

template <typename T, s32 C>
class soArrayList {
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
    virtual s32 capacity() const;
    virtual bool isFull() const;

    s32 getFreeIndex() const { return m_freeIndex; }

    s32 shiftFreeArrayIndex(s32 idx);

    s32 m_freeIndex : 5;
    s32 m_topIndex : 5;
    s32 m_lastIndex : 5;
    s32 m_size : 5;
    soArrayListUnit<T, s8> m_units[C];
};

template <typename T, s32 C>
s32 soArrayList<T, C>::shiftFreeArrayIndex(s32 idx) {
    if (isFull() == true)
        return -1;
    if (idx < 0) {
        s32 freeIndex = getFreeIndex();
        m_freeIndex = m_units[m_freeIndex].m_next;
        if (m_freeIndex > 0)
            m_units[m_freeIndex].m_prev = -1;
        m_size++;
        return freeIndex;
    }
    if (idx >= capacity())
        return -1;
    const soArrayListUnit<T, s8>& curr = m_units[idx];
    if (static_cast<bool>(curr.m_inUse) == true)
        return -1;
    s32 next = curr.m_next;
    s32 prev = curr.m_prev;
    if (prev < 0 && next < 0)
        m_freeIndex = -1;
    else if (prev < 0) {
        m_units[next].m_prev = -1;
        m_freeIndex = curr.m_next;
    } else if (next < 0)
        m_units[prev].m_next = -1;
    else {
        m_units[prev].m_next = next;
        m_units[next].m_prev = prev;
    }
    m_size++;
    return idx;
}

template s32 soArrayList<wnPikminPikmin*, 10>::shiftFreeArrayIndex(s32 idx);
