#pragma force_active on
struct Object {
    virtual void init(short, signed char);
    short field4;
    short field6;
    short field8;
};

extern "C" void* lbl_27_data_7284[];

extern "C" Object* fn_27_281128(Object* self, int a, int b) {
    self->field4 = -1;
    self->field6 = 1;
    self->field8 = -1;
    *(void***)self = lbl_27_data_7284;
    self->init((short)a, (signed char)b);
    return self;
}
