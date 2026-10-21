#pragma force_active on
struct SubObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
};

struct Outer {
    char pad0[0xA0];
    SubObj sub;
};

extern "C" void fn_802E3390(Outer* self);

extern "C" void fn_802E34D8(Outer* self) {
    self->sub.v2C();
    fn_802E3390(self);
}
