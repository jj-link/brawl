#pragma force_active on

class wnPikminPikmin;

template <class T, int N>
class soArrayVector {
public:
    const T& getArrayValueConst(long i);
    char m_header[12];
    T m_array[N];
};

template <class T, int N>
const T& soArrayVector<T, N>::getArrayValueConst(long i) {
    return m_array[i];
}

template class soArrayVector<wnPikminPikmin*, 10>;
