#pragma force_active on
extern "C" unsigned char lbl_27_data_24C0[];
extern "C" void __dl__FPv(void*);

class Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

extern "C" Object* fn_27_22A38(Object* self, int flag) {
    if (self) {
        *(void**)self = lbl_27_data_24C0;
        self->v4();
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
