#include <types.h>
#include <bitset>
#pragma force_active on

class wnPikminPikmin;

class soArrayVectorCalcInterface {
public:
    virtual void substitution(s32, s32) = 0;
    virtual void onFull() = 0;
    virtual void offFull() = 0;
    virtual void setTopIndex(s32) = 0;
    virtual void setLastIndex(s32) = 0;
    virtual ~soArrayVectorCalcInterface() { }
};

template <class T>
class soArray {
public:
    virtual ~soArray() { }
};

template <class T>
class soArrayVectorAbstract : public soArray<T>, public soArrayVectorCalcInterface {
public:
    virtual ~soArrayVectorAbstract() { }
};

template <class T, s32 C>
class soArrayVector : public soArrayVectorAbstract<T> {
    s32 m_topIndex : sizeof(bit_width<C>) + 1;
    s32 m_lastIndex : sizeof(bit_width<C>) + 1;
    s32 m_size : sizeof(bit_width<C>) + 1;
    u32 m_isFull : 1;

    T m_elements[C];

public:
    virtual s32 getTopIndex() const;
};

template <class T, s32 C>
s32 soArrayVector<T, C>::getTopIndex() const {
    return m_topIndex;
}
template class soArrayVector<wnPikminPikmin*, 10>;
