#pragma force_active on
typedef unsigned int u32;
typedef int s32;

class wnPikminPikmin;

template <class T, int N>
class soArrayVector {
public:
    int getLastIndex() const;

    u32 m_0;
    u32 m_4;
    u32 m_8;
};

template <class T, int N>
int soArrayVector<T, N>::getLastIndex() const {
    return ((s32)((m_8 << 5) & 0xFC000000)) >> 27;
}

template class soArrayVector<wnPikminPikmin*, 10>;
