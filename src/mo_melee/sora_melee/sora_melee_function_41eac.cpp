#include <types.h>
#pragma force_active on

extern "C" void fn_27_41678(void* p, u32 addr);

struct soaBase {
    virtual void vf0();
    virtual void* getAddr(s32 off);
};

struct soaArg {
    u8 pad[4];
    s16 off4;
};

extern "C" void fn_27_41EAC(soaArg* a, soaBase* b, s32 off, u32 addr) {
    void* p = b->getAddr(a->off4 + off);
    fn_27_41678(p, addr);
}
