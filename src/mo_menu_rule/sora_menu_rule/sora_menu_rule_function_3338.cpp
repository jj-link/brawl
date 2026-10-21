#pragma force_active on

struct O {
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
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void call(int);
};

struct E {
    char pad[0x10];
    int field;
};

struct Self {
    char pad[0x64C];
    E** arr64c;
    int* arr650;
    O* obj654;
};

extern "C" void fn_18_3338(Self* self) {
    self->obj654->call(self->arr64c[0]->field);
    self->obj654->call(self->arr64c[2]->field);
    self->obj654->call(self->arr64c[4]->field);
    self->obj654->call(self->arr64c[5]->field);
    self->obj654->call(self->arr64c[6]->field);

    for (unsigned i = 0; i <= 2; ++i) {
        self->obj654->call(self->arr650[i]);
    }
}
