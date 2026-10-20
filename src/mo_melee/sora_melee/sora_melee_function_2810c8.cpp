#pragma force_active on
extern "C" void* lbl_27_data_59A0[];

struct Object {
    virtual void init(short, signed char);
    short value4;
    short value6;
    short value8;
};

extern "C" Object* fn_27_2810C8(Object* self, short arg1, signed char arg2) {
    self->value4 = -1;
    self->value6 = 8;
    self->value8 = -1;
    *(void***)self = lbl_27_data_59A0;
    self->init(arg1, arg2);
    return self;
}
