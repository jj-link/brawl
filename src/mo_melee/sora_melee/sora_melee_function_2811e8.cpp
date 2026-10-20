#pragma force_active on
struct Object {
    virtual void init(short, signed char);
    short a;
    short b;
    short c;
};

extern "C" void* lbl_27_data_29DE8[];

extern "C" Object* fn_27_2811E8(Object* self, short a, signed char b) {
    self->a = -1;
    self->b = 15;
    self->c = -1;
    *(void***)self = lbl_27_data_29DE8;
    self->init(a, b);
    return self;
}
