#pragma force_active on

struct Entry {
    void* unk0;
    int id;
};

class Array {
public:
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
    virtual void remove(int index);
};

class Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int size();
    void* pad0;
    void* pad1;
    void* pad2;
    Array m_array;
};

extern "C" void fn_27_38F9C8(Object* self, int arg1) {
    int result;
    if (arg1 <= -1) {
        result = -1;
        goto end;
    }
    {
        int n = self->size();
        int i;
        result = 0;
        for (i = 0; i < n; i++) {
            if (self->m_array.get(i)->id == arg1) {
                result = i;
                goto end;
            }
        }
        result = -1;
    }
end:
    if (result >= 0) {
        self->m_array.remove(result);
    }
}
