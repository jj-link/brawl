#pragma force_active on
struct acCmdInterpreterStackData;

template <class T, int N>
class soArrayVector {
public:
    void *m_0;
    void *m_4;
    unsigned int m_8;
    void offFull();
};

template <class T, int N>
void soArrayVector<T, N>::offFull() {
    m_8 &= 0xFDFFFFFF;
}

template class soArrayVector<acCmdInterpreterStackData, 1>;
