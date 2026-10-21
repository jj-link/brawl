#pragma force_active on

struct Entry {
    int unused;
    int id;
};

struct Array {
    virtual void v0();
    virtual void v1();
    virtual Entry* at(int);
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
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual int size();

    char padding[12];
    Array array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int n = size();
        for (int i = 0; i < n; ++i) {
            if (id == array.at(i)->id)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_507D8(Object* self, int id) {
    int index = self->find(id);
    if (index >= 0)
        self->array.select(index);
}
