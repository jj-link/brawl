#pragma force_active on

struct Entry {
    int unk0;
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
};

extern "C" void fn_27_1BC3E4(Object* self, int id) {
    int result;
    if (id <= -1) {
        result = -1;
    } else {
        int count = self->size();
        int i;
        result = 0;
        for (i = 0; i < count; ++i) {
            if (self->array.get(i)->id == id) {
                result = i;
                goto done;
            }
        }
        result = -1;
    }
done:
    if (result >= 0) {
        self->array.select(result);
    }
}
