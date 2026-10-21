#pragma force_active on
extern "C" void* lbl_27_data_9698[];
extern "C" void* lbl_27_data_2F978[];
extern "C" void* lbl_27_data_2F8E0[];

class Object {
public:
    virtual void init(short, signed char);
    short field4;
    short field6;
    short field8;
};

class Outer {
public:
    void** vt;
    Object obj;
    int field10;
};

extern "C" Outer* fn_27_17437C(Outer* self, int arg) {
    Object* o = &self->obj;
    self->vt = lbl_27_data_9698;
    o->field4 = -1;
    o->field6 = 3;
    o->field8 = -1;
    *(void***)o = lbl_27_data_2F978;
    o->init(-1, -1);
    self->field10 = arg;
    self->vt = lbl_27_data_2F8E0;
    *(void**)&self->obj = (char*)lbl_27_data_2F8E0 + 0x40;
    return self;
}
