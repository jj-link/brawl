#pragma force_active on
typedef int s32;

struct Obj {
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual int q();
    virtual void j();
    virtual void k();
};

struct State {
    int a;
    int b;
    int c;
    int d;
};

extern "C" void fn_27_196D20(State* self) {
    Obj* obj = (Obj*)self;
    if (!obj->q()) {
        if (self->d > 0) {
            self->d--;
            if (self->d <= 0) {
                self->c = 0;
            } else {
                self->c += 4;
            }
        } else if (self->b) {
            ((Obj*)self->b)->k();
        }
    }
}
