#include <types.h>
#pragma force_active on

struct SubObj {
    u8 pad[5];
    u8 flag;
};

class Base {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual SubObj* getObj(u32 arg);
    virtual u32 check();
};

extern "C" {
void fn_27_894D4(Base* self, u32 arg) {
    if (self->check() == 1) {
        SubObj* obj = self->getObj(arg);
        obj->flag |= 0x80;
    }
}
}
