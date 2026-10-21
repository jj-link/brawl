#pragma force_active on

struct Entry {
    int unused;
    int id;
};

struct Array {
    virtual void v0();
    virtual void v1();
    virtual Entry& at(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void select(int);
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
        for (int index = 0; index < count; index++) {
            if (id == array.at(index).id)
                return index;
        }
        return -1;
    }
};

extern "C" void fn_27_FCD74(Object* self, int id) {
    int index = self->find(id);
    if (index >= 0)
        self->array.select(index);
}
