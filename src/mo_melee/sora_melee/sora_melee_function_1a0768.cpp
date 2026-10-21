#pragma force_active on

typedef signed int s32;

struct acCmdInterpreterStackData {
    int x;
};

template <class T, int C>
class soArrayVector {
    void* m_v0;
    void* m_v1;
    unsigned int m_flags;
public:
    s32 isFull() const;
};

template <class T, int C>
s32 soArrayVector<T, C>::isFull() const {
    return (m_flags >> 25) & 1;
}

template class soArrayVector<acCmdInterpreterStackData, 1>;
