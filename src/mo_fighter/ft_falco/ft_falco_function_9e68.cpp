#pragma force_active on
class Object {
public:
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
    virtual void apply(int*);
};

extern "C" void fn_108_9E68(Object* self, int* values, int count) {
    if (values == 0 || count <= 0)
        return;

    for (int i = 0; i < count; ++i) {
        self->apply(values + i);
    }
}
