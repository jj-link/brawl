#pragma force_active on
typedef unsigned int u32;

class soKineticEnergy;

class Obj {
public:
    u32 m_pad;
    u32 m_id;
};

class Inner {
public:
    virtual void f0();
    virtual Obj* get();
};

template <class T, int N>
class soInstanceManagerFullPropertyVector {
public:
    u32 getId(long index);
    u32 m_pad[4];
    Inner m_inner;
};

template <class T, int N>
u32 soInstanceManagerFullPropertyVector<T, N>::getId(long index) {
    Inner* p = &m_inner;
    return p->get()->m_id;
}

template class soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>;
