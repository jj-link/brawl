#pragma force_active on

struct Entry {
    int unk0;
    int id;
};

struct Array {
    virtual void unused0();
    virtual void unused1();
    virtual Entry* get(int);
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void set(int);
};

struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual int size();

    char padding[12];
    Array array;
};

extern "C" void fn_27_1CC50C(Object* self, int id) {
    int result;
    if (id <= -1) {
        result = -1;
        goto exit;
    }
    {
        int count = self->size();
        for (int i = 0; i < count; i++) {
            if (self->array.get(i)->id == id) {
                result = i;
                goto exit;
            }
        }
        result = -1;
    }
exit:
    if (result >= 0)
        self->array.set(result);
}
