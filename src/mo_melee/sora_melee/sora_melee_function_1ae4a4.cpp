#pragma force_active on

struct soKineticEnergy;

struct Entry {
    void* value;
    int id;
};

struct Array {
    virtual void unused();
    virtual Entry* at(int);
    virtual Entry* get(int);
};

template <class T, int N>
struct soInstanceManagerFullPropertyVector {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual int size();

    int padding[3];
    Array array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int n = size();
        for (int i = 0; i < n; ++i) {
            if (id == array.get(i)->id)
                return i;
        }
        return -1;
    }

    Entry* at(long id);
};

template <class T, int N>
Entry* soInstanceManagerFullPropertyVector<T, N>::at(long id) {
    if (id <= -1)
        return array.at(0);

    int index = find(id);
    if (index < 0)
        return array.at(0);

    return array.at(index);
}

template Entry* soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>::at(long);
