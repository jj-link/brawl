#include <types.h>
#pragma force_active on

class soKineticEnergy;

template <class T> class soArray {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void push(T const& elm);
};

class Inner {
public:
    virtual void v0();
    virtual soKineticEnergy** get(s32 index);
    virtual void v2();
    virtual s32 count();
};

template <class T, int N> class soInstanceManagerFullPropertyVector {
public:
    u32 pad[4];
    Inner inner;
    void getPriorityArray(soArray<T*>& arr);
};

template <class T, int N>
void soInstanceManagerFullPropertyVector<T, N>::getPriorityArray(soArray<T*>& arr) {
    s32 count = inner.count();
    for (s32 i = 0; i < count; ++i) {
        T* value = inner.get(i);
        arr.push(value);
    }
}

template class soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>;
