// fn_117_EF10 tail-calls the fourth declared virtual of the object in r3:
// load its vtable pointer, fetch vtable offset 0x14 (the first declared
// virtual sits at 0x8 behind the RTTI/offset-to-top words, so 0x14 is the
// fourth slot), load into CTR and bctr.
#include <types.h>
#pragma force_active on

namespace {
struct EF10VirtHost {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
};
} // namespace

extern "C" void fn_117_EF10(EF10VirtHost* self) {
    self->slot14();
}
