#pragma force_active on
extern float lbl_805A43C0;

struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(float v);
};

extern "C" {
void fn_802E4BC8(Obj* self, float x) {
    self->f3(lbl_805A43C0 / x);
}
}
