#pragma force_active on

class soKineticEnergy;

struct Entry {
    int pad;
    int id;
};

class soVecBase {
public:
    virtual void v0();
    virtual void v1();
    virtual Entry* get(long index);
    virtual void v3();
};

class ManagerBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual long size() const;

    int m4;
    int m8;
    int mc;
    mutable soVecBase base;

    int find(long id) const {
        if (id <= -1)
            return -1;
        long count = size();
        for (int index = 0; index < count; ++index) {
            if (base.get(index)->id == id)
                return index;
        }
        return -1;
    }
};

template <typename T, int N>
class soInstanceManagerFullPropertyVector : public ManagerBase {
public:
    int isContain(long id) const;
};

template <typename T, int N>
int soInstanceManagerFullPropertyVector<T, N>::isContain(long id) const {
    int index = find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}

template class soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>;
