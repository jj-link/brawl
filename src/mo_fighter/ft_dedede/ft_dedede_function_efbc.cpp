#pragma force_active on
// fn_117_EFBC tail-calls the fourth declared virtual (vtable offset 0x14)
// of the polymorphic object the argument points to. The original words at
// .text[0xEFBC,0xEFCC) are 81830000 818C0014 7D8903A6 4E800420, i.e.
// lwz r12, 0(r3); lwz r12, 0x14(r12); mtctr r12; bctr.
//
// No relocation hits [0xEFBC,0xEFCC) in any import stream of ft_dedede.rel;
// the unit is reached as a member callback (the vtable slot itself is the
// referenced target in the original module), and the single vptr load shows
// the argument is the object itself rather than a holder with a target
// pointer at +0x00.

namespace {
// Interface of the polymorphic target. In this module's vtable convention
// the first declared virtual occupies slot 0x8, so the fourth declared
// virtual sits at 0x14 -- exactly the slot this unit jumps to.
struct DededeVirtualTarget {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void invoke();
};
} // namespace

extern "C" void fn_117_EFBC(DededeVirtualTarget* self) {
    self->invoke();
}
