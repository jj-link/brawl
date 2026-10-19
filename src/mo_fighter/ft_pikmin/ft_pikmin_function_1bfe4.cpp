#pragma force_active on
// ft_pikmin: fn_113_1BFE4
//
// Tail-call trampoline for a virtual callback (vtable offset 0x40):
//   lwz r12, 0x0(r3)    // load vtable pointer
//   lwz r12, 0x40(r12)  // load vtable entry at 0x40
//   mtctr r12
//   bctr                // tail jump
//
// The class below mirrors the receiver's vtable layout: CodeWarrior's ABI
// reserves two destructor slots, then 14 virtuals occupy 0x08..0x3C, so
// `callback` lands exactly at vtable offset 0x40.

struct PikminOwner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void callback();
};

extern "C" void fn_113_1BFE4(PikminOwner* self) {
    self->callback();
}
