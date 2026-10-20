#include <types.h>
#pragma force_active on

class Base {
public:
    virtual void vf0();
    virtual u8* vf1();
};

struct Owner {
    u8 pad[0x30];
    Base* m30;
    Base* m34;
};

extern "C" void fn_27_3AAA8(Owner* self, u32 p2, u32 value, u32 flag) {
    if (flag == 1) {
        u8* r = self->m34->vf1();
        *(u32*)(r + 0x1c) = value;
    } else {
        u8* r = self->m30->vf1();
        *(u32*)(r + 0x20) = value;
    }
}
