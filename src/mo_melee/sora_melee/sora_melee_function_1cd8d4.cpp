#pragma force_active on

struct Entry {
    int unknown;
    int id;
};

struct Array {
    virtual void u0();
    virtual void u1();
    virtual Entry* get(int index);
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual void u7();
    virtual void u8();
    virtual void u9();
    virtual void u10();
    virtual void u11();
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

extern "C" void fn_27_1CD8D4(Object* self, int index) {
    int result;
    if (index <= -1) {
        result = -1;
        goto exit;
    }
    {
        int n = self->size();
        int i;
        result = 0;
        for (i = 0; i < n; i++) {
            if (self->array.get(i)->id == index) {
                result = i;
                goto exit;
            }
        }
        result = -1;
    }
exit:
    if (result < 0) {
    } else {
        self->array.set(result);
    }
}
