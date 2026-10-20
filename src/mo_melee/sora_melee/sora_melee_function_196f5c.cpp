#include <types.h>
#pragma force_active on

class wnPikminPikmin;

template <typename ElementTy, typename IndexTy>
struct soArrayListUnit {
    u8 m_inUse : 1;
    ElementTy m_element;
    IndexTy m_prev;
    IndexTy m_next;

    static const s32 End = -1;

    soArrayListUnit();
    ~soArrayListUnit();
};

class soArrayBaseMirror {
public:
    virtual ~soArrayBaseMirror();
    virtual bool isNull() const;
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void clear();
};

template <typename T, s32 C>
class soArrayList;

template <>
class soArrayList<wnPikminPikmin*, 10> : public soArrayBaseMirror {
    s32 m_freeIndex : 5;
    s32 m_topIndex : 5;
    s32 m_lastIndex : 5;
    s32 m_size : 5;

    soArrayListUnit<wnPikminPikmin*, s8> m_units[10];

public:
    soArrayList();
    virtual ~soArrayList();
};

soArrayList<wnPikminPikmin*, 10>::soArrayList() : m_freeIndex(-1), m_topIndex(-1), m_lastIndex(-1) {
    ((soArrayBaseMirror*)this)->clear();
}
