#pragma force_active on
class wnPikminPikmin;

template <class T, class S>
class soArrayListUnit {
public:
    soArrayListUnit();

    unsigned char m_a : 1;
    unsigned char m_b : 7;
    unsigned char m_pad[7];
    S m_c;
    S m_d;
};

template <class T, class S>
soArrayListUnit<T, S>::soArrayListUnit() {
    m_a = 0;
    m_c = -1;
    m_d = -1;
}

template soArrayListUnit<wnPikminPikmin*, signed char>::soArrayListUnit();
