#pragma force_active on
struct Object {
    virtual void initialize(int, int);
    short field4;
    short field6;
    short field8;
};

extern "C" void* lbl_27_data_21048[];

extern "C" Object* fn_27_CDCC4(Object* self) {
    self->field4 = -1;
    self->field6 = 11;
    self->field8 = -1;
    *(void***)self = lbl_27_data_21048;
    self->initialize(-1, -1);
    return self;
}
