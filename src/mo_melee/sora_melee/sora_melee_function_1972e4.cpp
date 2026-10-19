#pragma force_active on
class wnPikminPikmin;

template <typename T, int N>
class soArrayList {
public:
    void erase(long idx);
    long getArrayIndex(long idx) const;
    void eraseSub(long idx);
};

template <typename T, int N>
void soArrayList<T, N>::erase(long idx) {
    eraseSub(getArrayIndex(idx));
}

template class soArrayList<wnPikminPikmin*, 10>;
