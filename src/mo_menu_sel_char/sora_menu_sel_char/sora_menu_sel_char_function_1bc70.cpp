#pragma force_active on
extern float lbl_10_rodata_870;
extern float lbl_10_rodata_874;

extern "C" void setFrameVisible__8MuObjectFf(void*, float);
extern "C" int fn_10_14620(void*, int);
extern "C" int fn_800B5854(void*, int, int, int, int);

struct Obj {
    char pad[0x10];
    void* field10;
};

struct State {
    char pad[0x1B4];
    int mode;
};

struct Base {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void call(void*);
};

struct Self {
    Base* base;
    Obj* obj;
    void* field8;
    Obj* other;
    void* field10;
    State* state;
    int field18;
    unsigned char flag;
};

extern "C" void fn_10_1BC70(Self* self) {
    Obj* obj = self->obj;
    int mode = self->state->mode;

    self->base->call(obj->field10);
    self->flag = 0;

    if (mode != 0) {
        setFrameVisible__8MuObjectFf(
            obj, mode == 1 ? lbl_10_rodata_870 : lbl_10_rodata_874);

        int index;
        if (self->state->mode == 1)
            index = fn_10_14620(self->state, 1) - 1;
        else
            index = 0;

        fn_800B5854(self->obj, index, 0x10, 1, 0);

        int index2;
        if (self->state->mode == 1)
            index2 = fn_10_14620(self->state, 1) - 1;
        else
            index2 = 4;

        fn_800B5854(self->other, index2, 0x10, 1, 0);
    }
}
