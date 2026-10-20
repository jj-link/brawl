#pragma force_active on
class wnPikminPikmin;

template <class T>
class soArray {
public:
    virtual ~soArray() { }
};

template <class T, int N>
struct soArrayListUnit {
    unsigned m_inUse : 1;
    T m_element;
    signed char m_prev;
    signed char m_next;
};

template <class T, int C>
class soArrayList : public soArray<T> {
    signed m_freeIndex : 5;
    signed m_topIndex : 5;
    signed m_lastIndex : 5;
    signed m_size : 5;
    soArrayListUnit<T, 8> m_units[C];
    long insertSub(long, long = -1);
public:
    virtual void unshift(const T& elm);
};

template <class T, int C>
void soArrayList<T, C>::unshift(const T& elm) {
    long idx = insertSub(-1);
    if (idx >= 0)
        m_units[idx].m_element = elm;
}

template class soArrayList<wnPikminPikmin*, 10>;
