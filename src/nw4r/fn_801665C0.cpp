#include <types.h>
#pragma force_active on

extern "C" u16 fn_8016F198(void* a, void* b, s32 c);

class Obj {
public:
    u8 pad[0x1c];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

extern "C" void fn_801665C0(u8* self) {
    if (*(u32*)(self + 0x20) & 0x200)
        return;
    u32 buf[1024];
    u16 count = fn_8016F198(self + 0xc0, buf, *(u16*)(self + 0xc8));
    u16 i;
    for (i = 0; i < count; i++) {
        ((Obj*)buf[i])->v4();
    }
}
