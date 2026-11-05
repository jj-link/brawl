#pragma force_active on
class wnPikminPikmin;

template <typename T>
class soArrayVectorAbstract {
public:
    bool isNull() const;
};

template <typename T>
bool soArrayVectorAbstract<T>::isNull() const {
    return false;
}

template bool soArrayVectorAbstract<wnPikminPikmin*>::isNull() const;
