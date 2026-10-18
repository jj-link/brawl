#pragma force_active on
// fn_117_C184 (ft_dedede, 16 bytes) tail-dispatches to vtable slot 0x58 of
// the object passed in r3. Original instructions:
//   81 83 00 00  lwz r12, 0x00(r3)
//   81 8C 00 58  lwz r12, 0x58(r12)
//   7D 89 03 A6  mtctr r12
//   4E 80 04 20  bctr
// i.e. a no-argument virtual call through the primary vtable pointer (no
// base-offset adjustment), returned to this unit's caller by the tail
// branch. With the committed slot convention (first declared virtual at
// vtable offset 0x8), 0x58 is the 21st declared virtual.

namespace {

struct DededeC184Target {
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
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
};

} // namespace

extern "C" void fn_117_C184(DededeC184Target* self) {
    self->slot58();
}
