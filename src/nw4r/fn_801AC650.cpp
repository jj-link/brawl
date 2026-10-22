#pragma force_active on
class Obj {
public:
    virtual void f0();
    virtual void f3(int, int, void*);
};

struct Owner {
    unsigned char padding[0x2888];
    Obj* obj;
};

extern "C" int fn_801AC650(Owner* self, Obj* arg1) {
    if (self->obj != 0 && self->obj != 0) {
        self->obj->f3(0x10003, 0, self);
        self->obj = 0;
    }
    self->obj = arg1;
    arg1->f3(0x10002, 0, self);
    return 1;
}
