#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_B16C8(void* p);

class fnWorkBase {
public:
    virtual void f2();
    virtual void* f3(u32 v);
};

struct fnWorkOwner {
    u8 pad[0x18];
    fnWorkBase* m_base;
};

extern "C" {
void fn_27_B2EE4(fnWorkOwner* self, u16 a, u32 b) {
    void* p = self->m_base->f3(b);
    *(u16*)((u8*)fn_27_B16C8(p) + 0xe) = a;
}
}
