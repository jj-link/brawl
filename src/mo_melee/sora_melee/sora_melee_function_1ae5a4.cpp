#pragma force_active on

class soKineticEnergy {
public:
    int x;
};

class soVecBase {
public:
    virtual void v0();
    virtual soKineticEnergy** v1();
    virtual void v2();
    virtual void v3();
};

template <typename T, int N>
class soInstanceManagerFullPropertyVector {
public:
    int m0;
    int m4;
    int m8;
    int mc;
    soVecBase base;

    T* atIndex(long index);
};

template <typename T, int N>
T* soInstanceManagerFullPropertyVector<T, N>::atIndex(long index) {
    (void)index;
    return (T*)this->base.v1();
}

template class soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>;
