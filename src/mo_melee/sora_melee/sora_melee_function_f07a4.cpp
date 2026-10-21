#pragma force_active on
struct Entry {
    int unknown;
    int id;
};

struct Array {
    virtual void v2();
    virtual void v3();
    virtual Entry* get(int);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void select(int);
};

struct Object {
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
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

extern "C" void fn_27_F07A4(Object* self, int id) {
    int index = self->find(id);
    if (index >= 0)
        self->array.select(index);
}
