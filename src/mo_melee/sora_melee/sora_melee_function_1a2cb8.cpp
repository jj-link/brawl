#include <types.h>
#pragma force_active on

class wnPikminPikmin;

template <class T, int C>
class soArrayVector {
    char _pad[8];
    s32 m_topIndex : 5;
    s32 m_lastIndex : 5;
    s32 m_size : 5;
    u32 m_isFull : 1;
public:
    bool isFull() const;
};

template <class T, int C>
bool soArrayVector<T, C>::isFull() const {
    return m_isFull;
}

template class soArrayVector<wnPikminPikmin*, 10>;
