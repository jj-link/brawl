#pragma force_active on
struct SubObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

struct OuterObj {
    char pad[0xa0];
    SubObj sub;
};

extern "C" {
void fn_802E35A4(OuterObj* self) {
    self->sub.f2();
}
}
