#pragma force_active on
class Object {
public:
    virtual void init(short, signed char);
    short field4;
    short field6;
    short field8;
};

extern "C" void* lbl_27_data_148A0[];

extern "C" Object* fn_27_281188(Object* self, short arg1, signed char arg2) {
    self->field4 = -1;
    self->field6 = 14;
    self->field8 = -1;
    *(void**)self = lbl_27_data_148A0;
    self->init(arg1, arg2);
    return self;
}
