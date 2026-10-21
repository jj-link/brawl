#pragma force_active on

struct Entry {
    int unk0;
    int id;
};

struct Array {
    virtual void x0();
    virtual void x1();
    virtual Entry* get(int);
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void x6();
    virtual void x7();
    virtual void x8();
    virtual void x9();
    virtual void x10();
    virtual void x11();
    virtual void select(int);
};

struct Object {
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual int size();
    char padding[12];
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

extern "C" void fn_27_1C9398(Object* self, int arg1) {
    int result = self->find(arg1);
    if (result >= 0)
        self->array.select(result);
}