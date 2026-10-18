#pragma force_active on
// fn_117_18030 is a 16-byte tail-call thunk: lwz r12, 0x0(r3); lwz r12,
// 0x2C(r12); mtctr r12; bctr. It is an entry of the .data callback table in
// ft_dedede and forwards the call to the tenth declared virtual (vtable
// offset 0x2C; with this toolchain's vtable convention the first declared
// virtual sits at slot 0x08) of the object passed in r3.
namespace {

class DededeRecordCallbackTarget {
public:
    virtual void slot_00(); // vtable +0x08
    virtual void slot_04(); // +0x0C
    virtual void slot_08(); // +0x10
    virtual void slot_0C(); // +0x14
    virtual void slot_10(); // +0x18
    virtual void slot_14(); // +0x1C
    virtual void slot_18(); // +0x20
    virtual void slot_1C(); // +0x24
    virtual void slot_20(); // +0x28
    virtual void slot_24(); // +0x2C: the slot this unit tail-calls
};

} // namespace

extern "C" void fn_117_18030(DededeRecordCallbackTarget* self) {
    self->slot_24();
}
