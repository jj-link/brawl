#pragma force_active on
// fn_117_1A554 is a virtual-call thunk: it loads the vtable pointer from the
// object in r3 and tail-calls the function at vtable offset 0x40 with r3
// unchanged. The class declares 15 virtuals so that slot40 lands at offset 0x40
// (first declared virtual at 0x08, one slot every 4 bytes).

class DededeVirtualHost {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
};

extern "C" void fn_117_1A554(DededeVirtualHost* self) {
    return self->slot40();
}
