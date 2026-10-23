#include <types.h>
#pragma force_active on

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

extern "C" void fn_106_6F68(Iface* iface, void* data, s32 count) {
    if (data == 0 || count <= 0) {
        return;
    }
    for (s32 i = 0; i < count; i++) {
        iface->func((void*)((u8*)data + 4 * i));
    }
}
