#pragma force_active on

struct Entry {
    int unk0;
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
    virtual void set(int);
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
        int count = size();
        for (int i = 0; i < count; ++i) {
            if (id == array.get(i)->id)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_1BBA00(Object* self, int id) {
    int index;
    if (id <= -1) {
        index = -1;
    } else {
        index = self->find(id);
    }
    if (index >= 0)
        self->array.set(index);
}
