#pragma force_active on
struct ObjData {
    short a;
    short b;
    short c;
    unsigned char pad[0x22];
};

struct Obj : ObjData {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

extern "C" void fn_80138630(Obj* self, int flag) {
    self->a = 0;
    self->b = 0;
    self->c = 0;
    if (flag != 0) {
        self->v3();
    } else {
        self->v2();
    }
}
