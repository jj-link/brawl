#pragma force_active on
class acCmdInterpreterStackData;

template <class T, int N>
class soArrayVector {
public:
    void setLastIndex(long idx);

    unsigned int m_0;
    unsigned int m_4;
    struct {
        unsigned int m_hi : 2;
        unsigned int m_idx : 2;
        unsigned int m_lo : 28;
    } m_8;
};

template <class T, int N>
void soArrayVector<T, N>::setLastIndex(long idx) {
    m_8.m_idx = idx;
}

template class soArrayVector<acCmdInterpreterStackData, 1>;
