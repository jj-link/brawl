#pragma force_active on
class Object {
public:
    virtual void init(short, signed char);
    short field4;
    short field6;
    short field8;
};

extern "C" void* lbl_27_data_2F978[];

extern "C" Object* fn_27_2812A8(Object* self, int a, int b) {
    self->field4 = -1;
    self->field6 = 3;
    self->field8 = -1;
    *(void***)self = lbl_27_data_2F978;
    self->init((short)a, (signed char)b);
    return self;
}
