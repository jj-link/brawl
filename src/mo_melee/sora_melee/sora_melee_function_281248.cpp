#pragma force_active on
struct Object {
    virtual void init(short, signed char);
    short field4;
    short field6;
    short field8;
};

extern "C" void* lbl_27_data_7270[];

extern "C" Object* fn_27_281248(Object* self, short arg1, signed char arg2) {
    self->field4 = -1;
    self->field6 = 0x11;
    self->field8 = -1;
    *(void***)self = lbl_27_data_7270;
    self->init(arg1, arg2);
    return self;
}
