#pragma force_active on
class soKineticEnergy;

class soInstanceManagerBaseA {
public:
    virtual ~soInstanceManagerBaseA() {}
    int pad[3];
};

class soInstanceManagerBaseB {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual unsigned int size() const;
};

template <class T, int N>
class soInstanceManagerFullPropertyVector : public soInstanceManagerBaseA, public soInstanceManagerBaseB {
public:
    virtual unsigned int size() const;
};

template <class T, int N>
unsigned int soInstanceManagerFullPropertyVector<T, N>::size() const {
    const soInstanceManagerBaseB& b = *this;
    return b.size();
}

template class soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>;
