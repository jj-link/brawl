#pragma force_active on
class wnPikminPikmin;

template <class T, int N>
class soArrayVector {
public:
    T* const& atFastAbstractSub(long i) const;

    int m_0;
    int m_4;
    int m_8;
    T* m_array[N];
};

template <class T, int N>
T* const& soArrayVector<T, N>::atFastAbstractSub(long i) const {
    long idx = (m_8 >> 27) + i;
    if (idx >= N) {
        idx -= N;
    }
    return m_array[idx];
}

template class soArrayVector<wnPikminPikmin*, 10>;
