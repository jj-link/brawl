#pragma force_active on
extern "C" unsigned char lbl_27_data_32C98[];

struct Base {
    void* vptr;
    unsigned char flag;
};

struct Object : Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();

    void* value;
};

extern "C" Object* fn_27_196664(Object* self, void* value) {
    self->flag = 0;
    *(void**)((char*)self + 8) = lbl_27_data_32C98;
    self->vptr = lbl_27_data_32C98 + 8;
    self->value = value;
    self->f4();
    return self;
}
