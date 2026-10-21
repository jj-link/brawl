#pragma force_active on
struct Entry {
    int unknown;
    int id;
};

struct Array {
    virtual void v0();
    virtual void v1();
    virtual Entry* get(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void set(int);
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

extern "C" void fn_27_26404C(Object* self, int id) {
    int result;
    if (id <= -1) {
        result = -1;
        goto done;
    }
    {
        int count = self->size();
        for (int i = 0; i < count; i++) {
            if (id != self->array.get(i)->id)
                continue;
            result = i;
            goto done;
        }
        result = -1;
    }
done:
    if (result >= 0) {
        self->array.set(result);
    }
}
