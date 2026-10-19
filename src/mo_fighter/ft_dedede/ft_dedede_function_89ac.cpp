#include <types.h>
#pragma force_active on

// Virtual interface used by the parameter/accesser tables. The dispatched
// method sits at vtable offset 0x38 (12th virtual function, 1-based).
class Iface {
public:
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void func(void*);
};

// Walks an array of `count` 4-byte entries in `data`, dispatching each entry
// through the object's virtual method (vtable slot 0x30) together with a
// pointer to that entry.
extern "C" void fn_117_89AC(Iface* iface, void* data, s32 count) {
    if (data == 0 || count <= 0) {
        return;
    }
    for (s32 i = 0; i < count; i++) {
        iface->func((void*)((u8*)data + 4 * i));
    }
}
