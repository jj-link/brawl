#pragma force_active on

extern "C" void __dl__FPv(void*);
extern unsigned char lbl_804666D8[];

class Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

extern "C" Object* fn_800730A4(Object* self, int flag) {
    if (self) {
        *(void**)self = lbl_804666D8;
        self->v2();
        self->v5();
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
