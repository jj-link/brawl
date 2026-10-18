#pragma force_active on
struct Entry {
    int unknown;
    int id;
};

struct Array {
    virtual void unused();
    virtual Entry* at(int);
    virtual Entry* get(int);
};

struct Object {
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
};

extern "C" Entry* fn_27_AFB14(Object* self, int id) {
    if (id <= -1)
        return self->array.at(0);

    int index = self->find(id);
    if (index < 0)
        return self->array.at(0);

    return self->array.at(index);
}
