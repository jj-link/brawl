#pragma force_active on
typedef unsigned int u32;

struct acCmdInterpreterStackData {
    int dummy;
};

template <class T, int N>
class soArrayVector {
public:
    void setTopIndex(long idx);

    u32 m_0;
    u32 m_4;
    u32 m_top : 2;
    u32 m_rest : 30;
};

template <class T, int N>
void soArrayVector<T, N>::setTopIndex(long idx) {
    m_top = idx;
}

template class soArrayVector<acCmdInterpreterStackData, 1>;
