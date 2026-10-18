#pragma force_active on
// fn_96_11608: tail-calls a virtual function at vtable offset 0x10 of an object embedded at offset 0x1B0DC.
// Untested: the last diff showed slot4 compiled to offset 0x18, so this calls slot2 to target offset 0x10.

struct fn_96_11608_Sub {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};

struct fn_96_11608_Owner {
    char pad[0x1B0DC];
    fn_96_11608_Sub sub;
};

extern "C" void fn_96_11608(fn_96_11608_Owner* self) {
    self->sub.slot2();
}
