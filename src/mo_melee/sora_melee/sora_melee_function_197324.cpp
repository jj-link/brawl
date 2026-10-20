#pragma force_active on
typedef unsigned int u32;
typedef int s32;

class wnPikminPikmin;

struct soArrayListBits {
    u32 pad : 15;
    s32 size : 5;
};

template <class T, int N>
class soArrayList {
public:
    u32 m_vtbl_or_pad;
    soArrayListBits m_bits;
    s32 size() const;
};

template <class T, int N>
s32 soArrayList<T, N>::size() const {
    return m_bits.size;
}

template class soArrayList<wnPikminPikmin*, 10>;
