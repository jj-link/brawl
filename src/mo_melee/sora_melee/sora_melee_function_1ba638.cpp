#pragma force_active on

struct Entry {
    int unused;
    int id;
};

struct Array {
    virtual void s0();
    virtual void s1();
    virtual Entry& at(int);
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
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
        for (int i = 0; i < n; i++) {
            if (id == array.at(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_1BA638(Object* self, int id) {
    int index = self->find(id);
    if (index >= 0)
        self->array.select(index);
}
