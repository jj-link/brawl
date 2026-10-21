#pragma force_active on

struct Entry {
    int unused;
    int id;
};

struct Array {
    virtual void unused0();
    virtual void unused1();
    virtual Entry* at(int);
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

        int count = size();
        for (int i = 0; i < count; ++i) {
            if (id == array.at(i)->id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_2EB66C(Object* self, int id) {
    return self->find(id);
}
