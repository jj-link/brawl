#pragma force_active on

struct Entry {
    int unused;
    int id;
};

struct Array {
    virtual void dummy();
    virtual void select(int);
    virtual Entry& at(int);
};

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int size();

    char padding[12];
    Array array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int count = size();
        for (int i = 0; i < count; ++i) {
            if (id == array.at(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_F7F2C(Object* self, int id) {
    if (id <= -1) {
        self->array.select(0);
    } else {
        int index = self->find(id);
        if (index < 0)
            self->array.select(0);
        else
            self->array.select(index);
    }
}
