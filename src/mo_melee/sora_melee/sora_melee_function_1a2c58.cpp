#pragma force_active on
typedef unsigned int u32;
typedef long s32;

class wnPikminPikmin;

template <class T, int N>
class soArrayVector {
public:
    void setTopIndex(s32 idx);
    u32 m_0;
    u32 m_4;
    u32 m_topIndex : 5;
};

template <class T, int N>
void soArrayVector<T, N>::setTopIndex(s32 idx) {
    m_topIndex = idx;
}

template class soArrayVector<wnPikminPikmin*, 10>;
