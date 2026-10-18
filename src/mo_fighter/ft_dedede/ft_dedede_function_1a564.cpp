#pragma force_active on
// fn_117_1A564 is a 16-byte tail-call forwarder: it loads the object's
// vtable pointer (r3), takes the entry at +0x40 (the 15th declared virtual),
// and branches to it.
namespace {
struct DededeVirtualForwarder {
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void f3c();
    virtual int f40();
};
} // namespace

extern "C" int fn_117_1A564(DededeVirtualForwarder* self) {
    return self->f40();
}
