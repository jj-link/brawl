#pragma force_active on
struct Object {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void call(int*);
};

extern "C" void fn_107_A75C(Object* self, int* values, int count)
{
    if (values == 0 || count <= 0) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        self->call(&values[i]);
    }
}
