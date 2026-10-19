#pragma force_active on
struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void apply(int*);
};

extern "C" void fn_104_980C(Object* self, int* values, int count) {
    if (values == 0 || count <= 0) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        self->apply(&values[i]);
    }
}
