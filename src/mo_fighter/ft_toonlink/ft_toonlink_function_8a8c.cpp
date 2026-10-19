#pragma force_active on
struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void apply(int*);
};

extern "C" void fn_121_8A8C(Object* self, int* values, int count)
{
    if (values == 0 || count <= 0) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        self->apply(&values[i]);
    }
}
