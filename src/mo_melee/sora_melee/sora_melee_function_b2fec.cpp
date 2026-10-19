#include <types.h>
#pragma force_active on

struct B2FECInterface {
    virtual void* unused0();
    virtual void* call();
};

struct B2FECObject {
    u8 pad[0x18];
    B2FECInterface* interface;
};

extern "C" u32 fn_27_B16C8(void*);

extern "C" void fn_27_B2FEC(B2FECObject* self) {
    void* target = self->interface->call();
    u32* work = reinterpret_cast<u32*>(fn_27_B16C8(target));
    *reinterpret_cast<u32*>(reinterpret_cast<u8*>(work) + 8) &= ~0x1000;
}
