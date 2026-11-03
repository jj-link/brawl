#pragma force_active on

struct Entry {
    int unused;
    int id;
};

struct Array {
    virtual void x0();
    virtual void x1();
    virtual Entry* get(int);
};

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int size();

    int pad[3];
    Array array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int n = size();
        for (int i = 0; i < n; ++i) {
            if (array.get(i)->id == id)
                return i;
        }
        return -1;
    }
};

extern "C" int fn_27_29286C(Object* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}