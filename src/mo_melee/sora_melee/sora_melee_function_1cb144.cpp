#pragma force_active on

struct Entry {
    int unused;
    int id;
};

struct Array {
    virtual void x0();
    virtual void x1();
    virtual Entry* get(int);
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void x6();
    virtual void x7();
    virtual void x8();
    virtual void x9();
    virtual void x10();
    virtual void select(int);
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
        if (id <= -1)
            return -1;
        int n = size();
        for (int i = 0; i < n; i++) {
            if (array.get(i)->id == id)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_1CB144(Object* self, int id) {
    int result = self->find(id);
    if (result >= 0)
        self->array.select(result);
}
