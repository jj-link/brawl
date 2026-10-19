#pragma force_active on
class Array {
public:
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int capacity();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int size();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual void set(float value, int index, int count);
};

extern "C" void fn_27_C2EE8(Array* self, int index, Array* other, float value) {
    int count = other->size();
    if (count > other->capacity()) {
        count = other->capacity();
    }
    self->set(value, index, count);
}
