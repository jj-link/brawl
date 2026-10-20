#include <types.h>
#pragma force_active on

class ModInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
};

struct ModHolder {
    u8 pad[0x1c];
    ModInner* inner;
};

extern "C" void fn_27_2636F0(u8* module) {
    ModHolder* holder = *(ModHolder**)(module + 0x180);
    holder->inner->vf7();
}
