#pragma force_active on
struct acCmdInterpreterStackData {
    int m_dummy;
};

template <typename T, int N>
class soArrayVector {
public:
    virtual ~soArrayVector();
    T m_data[N];
};

template <typename T, int N>
soArrayVector<T, N>::~soArrayVector() { }

template class soArrayVector<acCmdInterpreterStackData, 1>;
