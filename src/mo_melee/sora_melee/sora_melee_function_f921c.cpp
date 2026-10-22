#pragma force_active on

struct Entry {
    int unknown;
    int id;
};

struct Array {
    virtual void v0();
    virtual void v1();
    virtual Entry* get(int index);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void select(int index);
};

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int size();
    int padding[3];
    Array array;

    int find(int id) {
        int count = size();
        for (int i = 0; i < count; ++i) {
            if (id == array.get(i)->id)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_F921C(Object* self, int id) {
    int index;
    if (id <= -1) {
        index = -1;
    } else {
        index = self->find(id);
    }
    if (index >= 0)
        self->array.select(index);
}
