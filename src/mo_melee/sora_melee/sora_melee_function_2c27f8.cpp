#include <so/so_array.h>
#pragma force_active on

union Packed {
    struct { s32 freeIndex : 8; s32 top : 8; s32 last : 8; s32 size : 8; } fields;
    s32 word;
};

class Object_vptr_0 {
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
    virtual s32 slot13();
    virtual bool slot14();

    s32 getFreeIndex() const { return m_freeIndex; }

    union {
        struct {
            s32 m_freeIndex : 8;
            s32 m_topIndex : 8;
            s32 m_lastIndex : 8;
            s32 m_size : 8;
        };
        s32 packed;
    };
    soArrayListUnit<int, s8> m_units[128];
};

extern "C" s32 fn_27_2C27F8(Object_vptr_0* self, s32 idx) {
    if (self->slot14() == true)
        return -1;
    if (idx < 0) {
        Packed packed;
        packed.word = self->packed;
        s32 freeIndex = packed.fields.freeIndex;
        packed.fields.freeIndex = self->m_units[freeIndex].m_next;
        self->packed = packed.word;
        if (packed.fields.freeIndex > 0)
            self->m_units[packed.fields.freeIndex].m_prev = -1;
        self->m_size++;
        return freeIndex;
    }
    if (idx >= self->slot13())
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