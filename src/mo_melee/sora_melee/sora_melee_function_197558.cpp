#pragma force_active on
class wnPikminPikmin;

template <class T, int C>
class soArrayList {
public:
    virtual bool isNull() const;
};

template <>
bool soArrayList<wnPikminPikmin*, 10>::isNull() const {
    return false;
}
