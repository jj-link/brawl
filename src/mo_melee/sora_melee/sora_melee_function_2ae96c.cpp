#include <so/so_array.h>
#pragma force_active on

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual s32 fn_27_14D08();
    virtual bool fn_27_14EDC();

    s32 getFreeIndex() const { return m_freeIndex; }

    s32 m_freeIndex : 5;
    s32 m_topIndex : 5;
    s32 m_lastIndex : 5;
    s32 m_size : 5;
    soArrayListUnit<int, s8> m_units[16];
};

extern "C" s32 fn_27_2AE96C(Class_1250* self, s32 idx) {
    if (self->fn_27_14EDC() == true)
        return -1;
    if (idx < 0) {
        s32 freeIndex = self->getFreeIndex();
        self->m_freeIndex = self->m_units[self->m_freeIndex].m_next;
        if (self->m_freeIndex > 0)
            self->m_units[self->m_freeIndex].m_prev = -1;
        self->m_size++;
        return freeIndex;
    }
    if (idx >= self->fn_27_14D08())
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
