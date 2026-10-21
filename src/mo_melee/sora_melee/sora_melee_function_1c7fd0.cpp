#pragma force_active on

struct Entry {
    int unused;
    int id;
};

struct Array {
    virtual void a0();
    virtual void a1();
    virtual Entry& at(int);
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
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

        int n = size();
        for (int i = 0; i < n; ++i) {
            if (id == array.at(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_1C7FD0(Object* self, int id) {
    int index = self->find(id);
    if (index >= 0)
        self->array.select(index);
}
