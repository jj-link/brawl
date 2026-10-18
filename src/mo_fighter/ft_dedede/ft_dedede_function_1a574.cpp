#pragma force_active on
// fn_117_1A574 forwards to the virtual at vtable offset 0x40 (slot 21) of
// its first argument and returns its result, i.e. lwz r12,0(r3);
// lwz r12,0x40(r12); mtctr r12; bctr.

class DededeSlot40 {
  public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v15();
};

extern "C" void fn_117_1A574(DededeSlot40* self) {
    self->v15();
}
