#pragma force_active on

struct soKineticEnergy;

struct Entry {
    int unused;
    int id;
};

struct Array {
    virtual void a0();
    virtual void a1();
    virtual Entry* at(int);
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void erase(int);
};

template <class T, int N>
struct soInstanceManagerFullPropertyVector {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int size();

    char padding[12];
    Array array;

    long find(long index) {
        if (index <= -1)
            return -1;

        int n = size();
        for (long idx = 0; idx < n; idx++) {
            if (index == array.at(idx)->id)
                return idx;
        }
        return -1;
    }

    void erase(long index);
};

template <class T, int N>
void soInstanceManagerFullPropertyVector<T, N>::erase(long index) {
    long idx = find(index);
    if (idx >= 0)
        array.erase(idx);
}

template void soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>::erase(long);
