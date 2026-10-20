#pragma force_active on
typedef unsigned char u8;

class soKineticEnergy;

template <class T, int N>
class soInstanceManagerFullPropertyVector {
public:
    T* atUnitIndexFast(long idx);

    u8 m_00[0x18];
    int m_18;
};

template <class T, int N>
T* soInstanceManagerFullPropertyVector<T, N>::atUnitIndexFast(long idx) {
    long shift = m_18 >> 28;
    long t = shift + idx;
    if (t >= N) {
        t -= N;
    }
    return (T*)((u8*)this + 0x1c + t * 12);
}

template soKineticEnergy** soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>::atUnitIndexFast(long);
