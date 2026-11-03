#pragma force_active on
#include <so/so_array.h>

class wnPikminPikmin;

template <>
void soArrayList<wnPikminPikmin*, 10>::eraseSub(s32 idx) {
    if (idx < 0 || idx >= static_cast<const soArray<wnPikminPikmin*>*>(this)->capacity())
        return;
    if (static_cast<const soArrayFixed<wnPikminPikmin*>*>(this)->size() == 1) {
        m_topIndex = End;
        m_lastIndex = End;
        clearElement(idx);
    } else {
        s32 next = getUnits()[idx].m_next;
        s32 prev = getUnits()[idx].m_prev;
        if (prev < 0) {
            m_units[next].m_prev = End;
            m_topIndex = next;
        } else if (next < 0) {
            m_units[prev].m_next = End;
            m_lastIndex = prev;
        } else {
            m_units[prev].m_next = next;
            m_units[next].m_prev = prev;
        }
        clearElement(idx);
    }
}
