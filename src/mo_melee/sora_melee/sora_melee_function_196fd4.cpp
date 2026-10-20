#include <types.h>
#pragma force_active on

class wnPikminPikmin;

template <class T, class S>
class soArrayListUnit {
public:
    T m_obj;
    S m_id;
    u32 m_data;
    ~soArrayListUnit();
};

template <class T, int N>
class soArrayList {
public:
    u32 m_head;
    u32 m_count;
    soArrayListUnit<T, signed char> m_units[N];
    ~soArrayList();
};

template <class T, int N>
soArrayList<T, N>::~soArrayList() { }

template class soArrayList<wnPikminPikmin*, 10>;
