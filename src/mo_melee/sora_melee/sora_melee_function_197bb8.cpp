#pragma force_active on
class wnPikminPikmin;

template <class T, class U>
class soArrayListUnit {
public:
    virtual ~soArrayListUnit();
};

template <class T, class U>
soArrayListUnit<T, U>::~soArrayListUnit() { }

template class soArrayListUnit<wnPikminPikmin*, signed char>;
