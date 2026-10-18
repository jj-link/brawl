#include <types.h>
#pragma force_active on

class fnOwner;

class fnChild {
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
    virtual void vf10();
    virtual void vf11(u32 a, fnOwner* owner, u32 c);
};

class fnOwner {
public:
    u8 pad[0x44];
    fnChild* m_44;
};

extern "C" {
void fn_27_2E700(fnOwner* self, u32 a, u32 c) {
    self->m_44->vf11(a, self, c);
}
}
