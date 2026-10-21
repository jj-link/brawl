#pragma force_active on
struct Entry {
    int unused;
    int id;
};

struct Array {
    virtual void v0();
    virtual void v1();
    virtual Entry& at(int);
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
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
        for (int i = 0; i < count; ++i) {
            if (id == array.at(i).id)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_FA5E4(Object* self, int id) {
    int index = self->find(id);
    if (index >= 0)
        self->array.select(index);
}
