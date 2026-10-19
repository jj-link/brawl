#pragma force_active on
class wnPikminPikmin;

template <class T, int N>
class soArrayList {
public:
    long getArrayIndex(long) const;
    void eraseSub(long);
    void shift();
};

template <class T, int N>
void soArrayList<T, N>::shift() {
    eraseSub(getArrayIndex(0));
}

template class soArrayList<wnPikminPikmin*, 10>;
