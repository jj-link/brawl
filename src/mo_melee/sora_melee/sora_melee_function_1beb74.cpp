#pragma force_active on

struct Entry {
    int unused;
    int id;
};

struct Array {
    virtual void unused0();
    virtual void unused1();
    virtual Entry* at(int);
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void select(int);
};

struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual int size();

    int padding[3];
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

extern "C" void fn_27_1BEB74(Object* self, int id) {
    int index = self->find(id);
    if (index >= 0)
        self->array.select(index);
}
