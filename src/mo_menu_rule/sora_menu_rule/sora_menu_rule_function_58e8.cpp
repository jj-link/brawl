#pragma force_active on
extern "C" {

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

struct F {
    char pad[0xC];
    int field;
};

struct Self {
    char pad[0x64C];
    E** arr64c;
    F*  ptr650;
    O*  obj654;
};

void fn_18_58E8(Self* self) {
    self->obj654->call(self->ptr650->field);
    unsigned i = 0x13;
    while (i <= 0x17) {
        self->obj654->call(self->arr64c[i]->field);
        i++;
    }
}

}
