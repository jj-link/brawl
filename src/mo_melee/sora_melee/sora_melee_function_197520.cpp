#pragma force_active on
class wnPikminPikmin;

template <class T, int C>
class soArrayList {
public:
    int capacity() const;
};

template <>
int soArrayList<wnPikminPikmin*, 10>::capacity() const {
    return 10;
}
