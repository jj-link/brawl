#pragma force_active on
#include <so/so_array.h>

class ArrayListLike : public soArray<void*> {
public:
    s32 m_freeIndex : 8;
    s32 m_topIndex : 8;
    s32 m_lastIndex : 8;
    s32 m_size : 8;
    soArrayListUnit<void*, s8> m_units[128];
    soArrayListUnit<void*, s8>* getUnits() { return m_units; }
};

extern "C" void fn_27_2C2200(ArrayListLike* self, s32 idx) {
    if (idx < 0 || idx >= self->capacity())
        return;
    if (self->size() == 1) {
        self->m_topIndex = -1;
        self->m_lastIndex = -1;
        if (idx >= 0) {
            self->m_units[idx].m_next = self->m_freeIndex;
            self->m_units[idx].m_prev = -1;
            self->m_units[idx].m_inUse = false;
            if (self->m_freeIndex > 0)
                self->m_units[idx].m_prev = idx;
            self->m_freeIndex = idx;
            self->m_size--;
        }
    } else {
        s32 next = self->getUnits()[idx].m_next;
        s32 prev = self->getUnits()[idx].m_prev;
        if (prev < 0) {
            self->m_units[next].m_prev = -1;
            self->m_topIndex = next;
        } else if (next < 0) {
            self->m_units[prev].m_next = -1;
            self->m_lastIndex = prev;
        } else {
            self->m_units[prev].m_next = next;
            self->m_units[next].m_prev = prev;
        }
        if (idx >= 0) {
            self->m_units[idx].m_next = self->m_freeIndex;
            self->m_units[idx].m_prev = -1;
            self->m_units[idx].m_inUse = false;
            if (self->m_freeIndex > 0)
                self->m_units[idx].m_prev = idx;
            self->m_freeIndex = idx;
            self->m_size--;
        }
    }
}