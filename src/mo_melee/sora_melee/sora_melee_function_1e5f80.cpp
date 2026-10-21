#pragma force_active on

struct Entry {
    int unknown;
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
    virtual void set(int index);
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

extern "C" void fn_27_1E5F80(Object* self, int key) {
    int result;
    if (key <= -1) {
        result = -1;
        goto exit;
    }
    {
        int n = self->size();
        int i;
        for (i = 0; i < n; i++) {
            if (self->array.get(i)->id == key) {
                result = i;
                goto exit;
            }
        }
        result = -1;
    }
exit:
    if (result >= 0) {
        self->array.set(result);
    }
}
