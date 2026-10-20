#pragma force_active on
struct acCmdInterpreterStackData {
    char pad[0x14];
};

template <typename T, int N>
class soArrayVector {
public:
    void* m_0;
    void* m_4;
    int m_8;

    T* atFastAbstractSub(long idx) const;
};

template <typename T, int N>
T* soArrayVector<T, N>::atFastAbstractSub(long idx) const {
    long i = (m_8 >> 30) + idx;
    if (i >= 1) {
        i -= 1;
    }
    return (T*)((char*)this + i * sizeof(T) + 0xc);
}

template class soArrayVector<acCmdInterpreterStackData, 1>;
