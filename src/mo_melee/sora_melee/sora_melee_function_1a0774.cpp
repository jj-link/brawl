#pragma force_active on
struct acCmdInterpreterStackData {
    int dummy;
};

template <class T, int N>
class soArrayVector {
public:
    long capacity() const;
};

template <class T, int N>
long soArrayVector<T, N>::capacity() const {
    return N;
}

template class soArrayVector<acCmdInterpreterStackData, 1>;
