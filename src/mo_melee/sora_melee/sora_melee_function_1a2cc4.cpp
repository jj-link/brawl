#pragma force_active on
class wnPikminPikmin;

template <class T, int N>
class soArrayVector {
public:
    int capacity() const;
};

template <>
int soArrayVector<wnPikminPikmin*, 10>::capacity() const {
    return 10;
}
