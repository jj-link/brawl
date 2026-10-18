#pragma force_active on
// fn_117_1A52C is a 16-byte virtual dispatch thunk (0x1A52C-0x1A53C):
//   lwz r12, 0x00(r3)   load the receiver's vtable pointer
//   lwz r12, 0x40(r12)  load the vtable slot at +0x40
//   mtctr r12           load CTR from it
//   bctr                branch, passing the caller's arguments through
//
// Under the Metrowerks GC vtable layout the typeinfo/vdestructor words
// occupy offsets 0x00 and 0x04, so the first declared virtual sits at 0x08
// (the same slot convention the committed sibling selectors use). Slot
// 0x40 is therefore the 15th declared virtual.

namespace {
class DededeVtableBase {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
};

class DededeVtableThunk : public DededeVtableBase {
public:
    virtual void v14(); // vtable offset 0x40, the thunk's target
};
} // namespace

extern "C" void fn_117_1A52C(DededeVtableThunk* self) {
    self->v14();
}
