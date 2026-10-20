#pragma force_active on
class wnPikminPikmin;

template <class T, int C>
class soArrayVector {
    void* m_vtable;
    void* m_calcVtable;
    unsigned int m_flags;
    T m_elements[C];
    static unsigned char __vt[];

public:
    soArrayVector();
};

template <>
soArrayVector<wnPikminPikmin*, 10>::soArrayVector() {
    m_vtable = __vt;
    m_calcVtable = __vt + 0x48;
    m_flags &= 0xFFFF;
}
