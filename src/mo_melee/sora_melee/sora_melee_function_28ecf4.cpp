#include <types.h>
#pragma force_active on

class SubObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(s32 arg, void* ptr);
    virtual void vf4();
    virtual void vf5();
};

struct OuterObj {
    u8 pad[0x2c34];
    SubObj sub;
};

extern "C" void fn_27_28ECF4(OuterObj* p) {
    p->sub.vf3(6, (u8*)p + 0xcc);
}
