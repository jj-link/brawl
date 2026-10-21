#pragma force_active on

struct Entry {
    int unused;
    int id;
};

struct Array {
    virtual void f0();
    virtual void f1();
    virtual Entry* get(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void select(int);
};

struct Object {
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual int size();
    int padding[3];
    Array array;

    int find(int id) {
        if (id <= -1)
            return -1;
        int count = size();
        for (int i = 0; i < count; ++i) {
            if (array.get(i)->id == id)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_F2550(Object* self, int id) {
    int index = self->find(id);
    if (index >= 0)
        self->array.select(index);
}
