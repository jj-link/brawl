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
    virtual void y0();
    virtual void y1();
    virtual void y2();
    virtual void y3();
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

extern "C" int fn_27_1C5A6C(Object* self, int id) {
    int index = self->find(id);
    return (static_cast<unsigned int>(index) >> 31) ^ 1;
}
