#pragma force_active on
struct soKineticEnergy;

struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

template <typename T, int N>
struct soInstanceManagerFullPropertyVector {
    int x0, x1, x2, x3;

    void clear();
};

template <>
struct soInstanceManagerFullPropertyVector<soKineticEnergy*, 4> {
    int x0, x1, x2, x3;
    Base b;

    void clear();
};

void soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>::clear() {
    b.v8();
}
