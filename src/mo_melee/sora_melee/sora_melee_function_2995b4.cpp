#include <types.h>
#pragma force_active on

struct VFunc {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f6(u32 arg);
};

extern "C" {
void fn_27_2995B4(void*, u8* p) {
    VFunc* obj = *(VFunc**)(*(u8**)(*(u8**)(p + 0x60) + 0xd8) + 0x64);
    obj->f6(0x10000000);
}
}
