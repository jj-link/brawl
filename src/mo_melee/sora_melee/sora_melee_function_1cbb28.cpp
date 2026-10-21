#pragma force_active on
struct Entry {
    int unk0;
    int id;
};

struct Array {
    virtual void v0();
    virtual void v1();
    virtual Entry* get(int index);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void set(int index);
};

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int size();

    int pad0;
    int pad1;
    int pad2;
    Array m_array;
};

extern "C" void fn_27_1CBB28(Object* self, int id) {
    int result;
    if (id <= -1) {
        result = -1;
    } else {
        int count = self->size();
        result = 0;
        for (int i = 0; i < count; i++) {
            if (self->m_array.get(i)->id == id) {
                result = i;
                goto exit;
            }
        }
        result = -1;
    }
exit:
    if (result >= 0) {
        self->m_array.set(result);
    }
}
