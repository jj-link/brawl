#pragma force_active on
class wnPikminPikmin;

template <class T, class I>
class soArrayListEnumerator;

template <>
class soArrayListEnumerator<wnPikminPikmin*, signed char> {
public:
    virtual void unused();

    signed char index;
    wnPikminPikmin** data;
    int count;

    soArrayListEnumerator(wnPikminPikmin** p, int n)
        : index(0), data(p), count(n) {}
};

template <class T, int N>
class soArrayList {
public:
    virtual void unused();

    unsigned int flags : 5;
    signed int count : 5;
    unsigned int rest : 22;
    T data[N];

    soArrayListEnumerator<T, signed char> getEnumerator();
};

template <>
soArrayListEnumerator<wnPikminPikmin*, signed char>
soArrayList<wnPikminPikmin*, 10>::getEnumerator() {
    return soArrayListEnumerator<wnPikminPikmin*, signed char>(data, count);
}
